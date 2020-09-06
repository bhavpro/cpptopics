#include <bits/stdc++.h>

using namespace std;

#define vv vector<vector<int>>

int rec(vv &matrix, int r, int c, unordered_map<int, int> &m, int i = 0, int xors = 0)
{
    // base
    if (i == r)
    {
        if (xors > 0)
        {
            cout << "TAK\n";
            for (int k = 0; k < r; k++)
            {
                cout << m[k] << " ";
            }
            return -1;
        }
        else
            return 0;
    }

    // rec
    for (int k = 0; k < c; k++)
    {
        m[i] = k + 1;
        if (rec(matrix, r, c, m, i + 1, xors ^ matrix[i][k]) == -1)
        {
            return -1;
        }
    }
    if (i == 0)
    {
        cout << "NIE";
    }
    return 0;
}

void solve(vv &matrix, int r, int c)
{
    unordered_map<int, int> m;
    rec(matrix, r, c, m);
}

void solve1(vv &matrix, int r, int c)
{
    vector<int> ans(r, 0);
    int xors = 0;
    for (int i = 0; i < r; i++)
    {
        xors ^= matrix[i][0];
    }
    int i = 0;
    while (xors <= 0 && i < r)
    {
        for (int j = 1; j < c; j++)
        {
            int prev = ans[i];
            if (matrix[i][ans[i]] == matrix[i][j])
            {
                continue;
            }
            else
            {
                ans[i] = j;
                cout << "TAK\n";
                for (int i = 0; i < r; i++)
                    cout << ans[i] + 1 << " ";
                return;
            }
        }
        i++;
    }
    if (xors > 0)
    {
        cout << "TAK\n";
        for (int x : ans)
            cout << x + 1 << " ";
    }
    else
        cout << "NIE";
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cout.tie(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int m, n;
    cin >> n >> m;
    vv matrix(n, vector<int>(m));
    bool same = true;
    int num;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (i == j && i == 0)
            {
                same = matrix[i][j];
            }
            else
            {
                if (same != matrix[i][j])
                {
                    same = false;
                }
            }
        }
    }
    if (same == true && !(n & 1) || (n & 1) && same == true && matrix[0][0] == 0)
        cout << "NIE";
    else if (same == true && (n & 1))
    {
        cout << "TAK\n";
        for (int i = 0; i < n; i++)
        {
            cout << 1 << " ";
        }
    }
    else
        solve1(matrix, n, m);
    return 0;
}
