#include <utility>

using namespace std;

int dp[601][101][101] = {0};

pair<int, int> c01(string str)
{
    pair<int, int> ans = {0, 0};
    for (char x : str)
        if (x == '0')
            ans.first++;
        else
            ans.second++;
    return ans;
}

int rec(vector<string> &strs, int m, int n, int si = 0, int ct = 0)
{

    if (si == strs.size())
        return ct;

    // rec
    string str = strs[si];
    pair<int, int> c = c01(str);
    int a1 = -1;
    if (m - c.first >= 0 && n - c.second >= 0)
    {
        if (dp[si + 1][m - c.first][n - c.second] == 0)
            a1 = rec(strs, m - c.first, n - c.second, si + 1, ct + 1);
        else
            a1 = dp[si + 1][m - c.first][n - c.second];
    }

    int a2 = -1;
    if (dp[si + 1][m][n] == 0)
        a2 = rec(strs, m, n, si + 1, ct);
    else
        a2 = dp[si + 1][m][n];

    dp[si][m][n] = max(a1, a2);
    return dp[si][m][n];
}

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        for (int i = 0; i < 601; i++)
            for (int j = 0; j < 101; j++)
                for (int k = 0; k < 101; k++)
                    dp[i][j][k] = 0;
        return rec(strs, m, n);
    }
};