#include <bits/stdc++.h>

using namespace std;

int countpalin(string s)
{
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int k = 0; k < n; k++)
    {
        for (int i = 0, j = k; i < n - k; i++, j++)
        {
            if (i == j || ((s[i] == s[j]) && ((i + 1 == j) || (dp[i + 1][j - 1]))))
                dp[i][j] = true;
        }
    }

    int count = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0, j = k; i < n - k; i++, j++)
        {
            if (dp[i][j])
                count++;
        }
    }
    return count;
}

int main()
{
    string s;
    cin >> s;
    cout << countpalin(s);
}