#include <bits/stdc++.h>

using namespace std;

int kthGrammar(int N, int K)
{
    vector<bool> dp(K);
    for (int i = 0; i < K; i++)
    {
        if (i == 0)
            dp[0] = 0;
        else if (i & 1)
            dp[i] = !dp[i >> 1];
        else
            dp[i] = dp[i >> 1];
    }
    return dp[K - 1];
}

bool help(int k)
{
    // base
    if (k == 0)
        return 0;

    // rec

    if (k & 1)
        return !help(k >> 1);
    return help(k >> 1);
}

int kthGrammarrec(int N, int K)
{
    return help(K - 1);
}
