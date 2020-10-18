#include <bits/stdc++.h>

using namespace std;

vector<int> sums(vector<int> a, int n, int sum)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                dp[i][0] = 1;
            else if (i == 0)
                dp[0][j] = 0;
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (j - a[i - 1] >= 0)
                    dp[i][j] = dp[i][j] || dp[i - 1][j - a[i - 1]];
            }
        }
    }

    vector<int> ele;
    for (int i = 1; i <= sum; i++)
    {
        if (dp[n][i])
            ele.push_back(i);
    }
    return ele;
}

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
        sum += x;
    }

    vector<int> dp = sums(a, n, sum);
    cout << dp.size() << "\n";
    for (int x : dp)
        cout << x << " ";
}