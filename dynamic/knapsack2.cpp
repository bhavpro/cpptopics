#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> arr2d;

int maxprice(int N, int W, const vector<int> &wt, const vector<int> &value)
{
    arr2d dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            int val1 = dp[i - 1][j];
            int val2 = 0;
            if (j - wt[i - 1] >= 0)
                val2 = dp[i - 1][j - wt[i - 1]] + value[i - 1];
            dp[i][j] = max(val1, val2);
        }
    }
    return dp[N][W];
}

int main()
{
    int N, W;
    cin >> N >> W;
    vector<int> wt(N);
    vector<int> value(N);
    for (int i = 0; i < N; i++)
        cin >> wt[i] >> value[i];

    cout << maxprice(N, W, wt, value);
    return 0;
}