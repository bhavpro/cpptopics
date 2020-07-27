#include <bits/stdc++.h>

using namespace std;
int coun = 0;

int maxi(int house[], int n, int i = 0)
{
    coun++;
    static int dp[50];
    // base
    if (i >= n)
        return 0;

    // rec
    int sel = house[i] + (dp[i + 2] == 0 ? maxi(house, n, i + 2) : dp[i + 2]);
    int unsel = dp[i + 1] == 0 ? maxi(house, n, i + 1) : dp[i + 1];
    dp[i] = max(sel, unsel);
    return dp[i];
}

int dpmaxi(int house[], int n)
{
    int dp[50];
    memset(dp, 0, sizeof(dp));
    for (int i = n - 1; i >= 0; i--)
    {
        coun++;
        dp[i] = max(house[i] + dp[i + 2], dp[i + 1]);
    }
    return dp[0];
}

int main()
{
    int house[] = {2, 3, 4, 5, 5, 7};
    int n = sizeof(house) / sizeof(int);
    cout << dpmaxi(house, n);
    cout << coun;
    return 0;
}