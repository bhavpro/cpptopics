#include <bits/stdc++.h>

using namespace std;

int msis(vector<int> arr)
{
    int n = arr.size();
    int maxele = arr[0];
    vector<int> dp(n);
    dp[0] = max(arr[0], 0);
    for (int i = 1; i < n; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        maxele = max(dp[i] += arr[i], maxele);
    }
    return maxele;
}

int main()
{
    vector<int> arr({10, 22, 9, 33, 21, 50, 41, 60, 80, 1});
    cout << msis(arr);
}