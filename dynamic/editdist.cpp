#include <iostream>
#include <string>
#include <climits>
#include <vector>

#define INF INT_MAX

using namespace std;

int memo[20][20];

int to(string init, string final, int i = 0, int j = 0)
{
    // base
    if (i == init.length())
    {
        memo[i][j] = final.length() - j;
        return memo[i][j];
    }

    if (j == final.length())
    {
        memo[i][j] = init.length() - i;
        return memo[i][j];
    }

    // rec
    if (init[i] == final[j])
    {
        memo[i][j] = to(init, final, i + 1, j + 1);
        return memo[i][j];
    }

    int a = memo[i][j + 1] == -1 ? to(init, final, i, j + 1) : memo[i][j + 1];
    int b = memo[i + 1][j] == -1 ? to(init, final, i + 1, j) : memo[i + 1][j];
    int c = memo[i + 1][j + 1] == -1 ? to(init, final, i + 1, j + 1) : memo[i + 1][j + 1];
    memo[i][j] = min(a, min(b, c)) + 1;
    return memo[i][j];
}

int convertdp(string init, string final)
{
    // base
    int dp[30][30];
    int len1 = init.length();
    int len2 = final.length();
    for (int i = 0; i <= len1; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 0; i <= len2; i++)
    {
        dp[i][0] = i;
    }

    // rec
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (init[i - 1] == final[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
                continue;
            }
            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
        }
    }
    return dp[len1][len2];
}

int main()
{
    string stri, strf;
    cin >> stri;
    cin >> strf;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            memo[i][j] = -1;
        }
    }
    cout << convertdp(stri, strf);
    cout << "\n"
         << to(stri, strf);
    return 0;
}