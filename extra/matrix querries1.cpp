#include <bits/stdc++.h>

using namespace std;

#define matrix vector<vector<int>>
#define matrixinit vector<vector<int>>(2, vector<int>(2))
int mod;

void multiplymatrix(matrix &ans, matrix &a, matrix b)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int temp = 0;
            for (int k = 0; k < 2; k++)
            {
                temp = (temp + (a[i][k] % mod * b[k][j] % mod) % mod) % mod;
            }
            ans[i][j] = temp;
        }
    }
}

void build(vector<matrix> &seg, vector<matrix> &a, int s, int e, int i)
{
    // base
    if (s == e)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int j = 0; j < 2; j++)
            {
                seg[i][k][j] = a[s][k][j];
            }
        }
        return;
    }

    // rec
    int mid = (s + e) >> 1;
    build(seg, a, s, mid, i << 1);
    build(seg, a, mid + 1, e, (i << 1) + 1);
    multiplymatrix(seg[i], seg[i << 1], seg[(i << 1) + 1]);
}

void query(vector<matrix> &seg, matrix &ans, int s, int e, int qs, int qe, int i)
{
    // base
    if (qs > e || qe < s)
    {
        return;
    }

    if (qs <= s && qe >= e)
    {
        multiplymatrix(ans, seg[i], ans);
        return;
    }

    // rec
    int mid = (s + e) >> 1;
    query(seg, ans, s, mid, qs, qe, i);
    query(seg, ans, mid + 1, e, qs, qe, i);
}

int main()
{
    int r, n, q;
    cin >> r >> n >> q;
    vector<matrix> seg(4 * n + 1, matrixinit);
    vector<matrix> a(n, matrixinit);
    mod = r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cin >> a[i][j][k];
            }
        }
    }
    build(seg, a, 0, n - 1, 1);
    while (q--)
    {
        int L, R;
        cin >> L >> R;
        matrix ans = matrixinit;
        ans[0][0] = ans[1][1] = 1;
        ans[0][1] = ans[1][0] = 0;
        query(seg, ans, 0, n - 1, L, R, 1);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}