#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

#define INF INT_MAX

using namespace std;

int memo[100] = {0};

int mincoin(int n, vector<int> arr)
{
    // base
    if (n < 0)
    {
        return -1;
    }

    if (n == 0)
    {
        return memo[0];
    }

    // rec
    int mini = INF;
    int len = arr.size();
    bool can = false; // can we make change
    for (int i = 0; i < len; i++)
    {
        if (n - arr[i] >= 0)
        {
            int temp = memo[n - arr[i]] == 0 ? mincoin(n - arr[i], arr) : memo[n - arr[i]];
            if (temp == -1)
            {
                continue;
            }
            mini = min(mini, temp);
            can = true; // yes we can make change
        }
    }

    return can == true ? mini + 1 : -1;
}

int mincoindp(int n, vector<int> arr)
{
    // base
    int dp[100];
    dp[0] = 0;
    int len = arr.size();
    int mini;

    // rec
    for (int i = 1; i <= n; i++)
    {
        // we chose a number
        mini = INF;

        for (int j = 0; j < len; j++)
        {
            // we chose a coin
            if (i - arr[j] >= 0 && dp[i - arr[j]] != -1) 
            {
                mini = min(mini, dp[i - arr[j]]);
            }
        }

        if(mini == INF)
        {
            dp[i] = -1;
        }
        else
        {
            dp[i] = mini + 1;
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int num;
    cin >> num;
    cout << mincoindp(num, arr);
    return 0;
}