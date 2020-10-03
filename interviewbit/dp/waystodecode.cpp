#include <bits/stdc++.h>

using namespace std;

int numDecodings(string A)
{
    int mod = 1e9 + 7;
    int n = A.size();
    vector<int> dp(n + 1);
    // trim string by rem front 0
    int s = 0;
    // for (s = 0; s < n && A[s] != '0'; s++)
    //     ;

    A = A.substr(s);

    dp[0] = 1;
    dp[1] = 1;
    if (A[0] == '0')
        return 0;
    for (int i = 2; i <= n; i++)
    {
        long long ans = dp[i - 1];
        int si = i - 1;
        if (A[si - 1] == '1' || A[si - 1] == '2' && A[si] <= '6')
            ans += dp[i - 2];
        if (A[si] == '0')
        {
            ans -= dp[i - 1];
            if (A[si - 1] != '1' && A[si - 1] != '2')
                return 0;
        }
        dp[i] = ans % mod;
    }
    return dp[n];
}
