#include <bits/stdc++.h>

using namespace std;

struct happy
{
    int a, b, c;
};

int maxhappiness(vector<happy> hap, int n)
{
    vector<vector<int>> dp(3, vector<int>(n + 1));

    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            dp[0][0] = 0;
            dp[1][0] = 0;
            dp[2][0] = 0;
        }
        else
        {
            dp[0][i] = hap[i - 1].a + max(dp[1][i - 1], dp[2][i - 1]);
            dp[1][i] = hap[i - 1].b + max(dp[0][i - 1], dp[2][i - 1]);
            dp[2][i] = hap[i - 1].c + max(dp[0][i - 1], dp[1][i - 1]);
        }
    }
    return max(dp[0][n], max(dp[1][n], dp[2][n]));
}

int main()
{
    int n;
    cin >> n;
    vector<happy> hap(n);
    for (happy &x : hap)
        cin >> x.a >> x.b >> x.c;
    cout << maxhappiness(hap, n);
    return 0;
}