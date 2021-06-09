#include <iostream>
#include <vector>

using namespace std;

int memo[1001][1001];

int rec(int number, int usingnum)
{
    // base
    if (!number)
    {
        memo[number][usingnum] = 1;
        return 1;
    }

    if (!usingnum)
        return 0;

    if (number < usingnum)
        return memo[number][usingnum] = (memo[number][number] == 0 ? rec(number, number) : memo[number][number]);

    // rec

    return memo[number][usingnum] = (!memo[number][usingnum - 1] ? rec(number, usingnum - 1) : memo[number][usingnum - 1]) + (!memo[number - usingnum][usingnum] ? rec(number - usingnum, usingnum) : memo[number - usingnum][usingnum]);
}

int dppart(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (i <= j)
                dp[i][j] += dp[i][j - i];
        }
    }
    return dp[n][n];
}

int main()
{
    int n;
    cin >> n;
    cout << rec(n, n) << " " << dppart(n);
    return 0;
}