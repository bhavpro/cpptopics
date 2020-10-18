#include <bits/stdc++.h>

using namespace std;

int orderab(int &a, int &b)
{
    int x = min(a, b);
    int y = max(a, b);
    a = x;
    b = y;
}

int totalcuts(int a, int b)
{
    int count = 0;
    while (a != b)
    {
        if (b == a)
            break;
        b -= a;
        orderab(a, b);
        count++;
    }
    return count;
}

int totalcutsdp(int a, int b)
{
    vector<vector<int>> dp(a + 1, vector<int>(b + 1));

    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = INT_MAX;
            else if (i == j)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = INT_MAX;
                for (int k = 1; k < i; k++)
                {
                    int a1 = k;
                    int a2 = i - k;
                    dp[i][j] = min(dp[i][j], dp[a1][j] + dp[a2][j] + 1);
                }
                for (int k = 1; k < j; k++)
                {
                    int b1 = k;
                    int b2 = j - k;
                    dp[i][j] = min(dp[i][j], dp[i][b1] + dp[i][b2] + 1);
                }
            }
        }
    }
    return dp[a][b];
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << totalcutsdp(a, b);
    return 0;
}