#include <iostream>
#include <climits>

#define INF INT_MAX

using namespace std;

int memo[10][10];

void initmemo()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            memo[i][j] = -1;
        }
    }
}

int minpath(int arr[][3], int i, int j)
{
    // base
    if (i == 0 && j == 0)
    {
        memo[i][j] = arr[i][j];
        return memo[i][j];
    }

    // rec
    int a = i != 0 ? (memo[i - 1][j] == -1 ? minpath(arr, i - 1, j) : memo[i - 1][j]) : INF;
    int b = j != 0 ? (memo[i][j - 1] == -1 ? minpath(arr, i, j - 1) : memo[i][j - 1]) : INF;
    memo[i][j] = min(a, b) + arr[i][j];
    return memo[i][j];
}

int minpathdp(int arr[][3], int n)
{
    // base
    int dp[10][10];

    // rec
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = arr[i][j];
                continue;
            }

            int a = i != 0 ? dp[i - 1][j] : INF;
            int b = j != 0 ? dp[i][j - 1] : INF;
            dp[i][j] = min(a, b) + arr[i][j];
        }
    }
    return dp[n - 1][n - 1];
}

int main()
{
    int arr[3][3] = {
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3}};

    int n = 3;
    initmemo();
    cout << minpathdp(arr, n);
    return 0;
}