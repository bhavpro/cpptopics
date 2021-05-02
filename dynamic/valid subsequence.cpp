#include <iostream>
#include <vector>

using namespace std;

bool vs(vector<int> &seq, vector<int> &ss)
{
    int n = seq.size();
    int m = ss.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = true;
            else if (j == 0)
                dp[i][j] = false;
            else if (dp[i][j - 1])
                dp[i][j] = true;
            else if ((seq[j - 1] == ss[i - 1]) && dp[i - 1][j])
                dp[i][j] = true;
            else
                dp[i][j] = false;
        }
    }

    return dp[m][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> s, ss;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        s.push_back(temp);
    }

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        ss.push_back(temp);
    }

    cout << vs(s, ss);

    return 0;
}
