#include <bits/stdc++.h>

using namespace std;

struct ss
{
    string str;
    int r, c;
};

void printallpath(vector<vector<int>> &arr, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i == 0 && j == 0)
                dp[i][j] = 0;
            else
            {
                int l = INT_MAX;
                int t = INT_MAX;
                if (i != 0)
                    t = dp[i - 1][j] + arr[i][j];
                if (j != 0)
                    l = dp[i][j - 1] + arr[i][j];
                dp[i][j] = min(l, t);
            }

    stack<ss> s;
    s.push({"", n - 1, m - 1});
    while (!s.empty())
    {
        ss t = s.top();
        s.pop();
        if (t.r == 0 && t.c == 0)
            cout << t.str << "\n";
        else
        {
            int r = t.r;
            int c = t.c;
            if (r == 0)
                s.push({t.str + "H", 0, c - 1});
            else if (c == 0)
                s.push({t.str + "V", r - 1, 0});
            else
            {
                if (dp[r - 1][c] == dp[r][c - 1])
                {
                    s.push({t.str + "H", r, c - 1});
                    s.push({t.str + "V", r - 1, c});
                }
                else if (dp[r - 1][c] > dp[r][c - 1])
                    s.push({});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (vector<int> &x : arr)
        for (int &ele : x)
            cin >> ele;

    printallpath(arr, n, m);
    return 0;
}