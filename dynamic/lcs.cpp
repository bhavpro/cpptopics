#include <iostream>

using namespace std;

int memo[20][20];

void stringdpchecker(string a, string b, int dp[20][20])
{
    cout << "\n\n";
    cout << "    ";
    for (int i = 0; i < b.length(); i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i <= a.length(); i++)
    {
        if (i - 1 == -1)
            cout << "  ";
        else
            cout << a[i - 1] << " ";
        for (int j = 0; j <= b.length(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

int lcs(string a, string b, int i = 0, int j = 0)
{
    // base
    if (i == a.length() || j == b.length())
    {
        memo[i][j] = 0;
        return memo[i][j];
    }

    // rec
    if (a[i] == b[j])
    {
        memo[i][j] = memo[i + 1][j + 1] == -1 ? 1 + lcs(a, b, i + 1, j + 1) : memo[i + 1][j + 1];
        return memo[i][j];
    }

    int t1 = memo[i][j + 1] == -1 ? lcs(a, b, i, j + 1) : memo[i][j + 1];
    int t2 = memo[i + 1][j] == -1 ? lcs(a, b, i + 1, j) : memo[i + 1][j];
    return max(t1, t2);
}

int lcsdp(string a, string b)
{
    // base
    int dp[20][20];
    int len1 = a.length();
    int len2 = b.length();
    for (int i = 0; i <= len1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= len2; j++)
    {
        dp[0][j] = 0;
    }

    // rec
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {

            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
            }
        }
    }
    return dp[len1][len2];
}

int main()
{
    string a, b;
    cin >> a;
    cin >> b;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            memo[i][j] = -1;
        }
    }
    cout << lcs(a, b);
    cout << "\n"
         << lcsdp(a, b);
    return 0;
}