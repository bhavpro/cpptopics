#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bitset<40> col, d1, d2;

void print(vector<vector<bool>> q)
{
    int r = q.size();
    int c = q.size();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << (q[i][j] == 1 ? 'Q' : '_');
        }
        cout << "\n";
    }
}

bool canplace(int r, int c, int n)
{
    if (col[c] == 1)
    {
        return false;
    }

    if (d1[r - c + n] == 1)
    {
        return false;
    }

    if (d2[r + c] == 1)
    {
        return false;
    }

    return true;
}

void setparam(int r, int c, int n)
{
    col[c] = 1;
    d1[r - c + n] = 1;
    d2[r + c] = 1;
}

void resetparam(int r, int c, int n)
{
    col[c] = 0;
    d1[r - c + n] = 0;
    d2[r + c] = 0;
}

void gen(int r, vector<vector<bool>> q)
{
    int n = q.size();
    // base
    if (r == n)
    {
        print(q);
        cout << "\n\n";
        return;
    }

    // rec
    for (int i = 0; i < n; i++)
    {
        if (canplace(r, i, n))
        {
            q[r][i] = 1;
            setparam(r, i, n);
            gen(r + 1, q);
            q[r][i] = 0;
            resetparam(r, i, n);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    col.reset();
    d1.reset();
    d2.reset();
    vector<vector<bool>> q(n, vector<bool>(n, 0));
    gen(0, q);
    return 0;
}