#include <bits/stdc++.h>
using namespace std;

int solve(const vector<string> &vos, int r, int c)
{
    int count = 0;
    for (int i = 0; i < c - 1; i++) // last row count downs
    {
        if (vos[r][i] == 'D')
        {
            count++;
        }
    }

    for (int i = 1; i <= r - 1; i++) // last col count rights
    {
        if (vos[i][c - 1] == 'R')
        {
            count++;
        }
    }
    return count;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<string> vos(r + 1, "");
        for (int i = 1; i <= r; i++)
        {
            cin >> vos[i];
        }
        cout << solve(vos, r, c) << "\n";
    }
    return 0;
}