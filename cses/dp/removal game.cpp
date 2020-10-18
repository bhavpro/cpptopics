#include <bits/stdc++.h>

using namespace std;

template <class T>
vector<vector<T>> _2darray(int r, int c)
{
    return vector<vector<T>>(r, vector<T>(c));
}

int maxscore(vector<int> a, int n)
{
    auto dp = _2darray<pair<int, int>>(n, n);
    bool fp = n & 1;

    for (int k = 0; k < n; k++)
    {
        int j = k;
        for (int i = 0; i < n - k; i++, j++)
        {
            if (i == j)
                if (fp == true)
                    dp[i][j] = {a[i], 0};
                else
                    dp[i][j] = {0, a[i]};
            else
            {
                if (fp == true)
                {
                    pair<int, int> temp1 = {dp[i][j - 1].first + a[j], dp[i][j - 1].second};
                    pair<int, int> temp2 = {dp[i + 1][j].first + a[i], dp[i + 1][j].second};
                    dp[i][j] = temp1.first > temp2.first ? temp1 : temp2;
                }
                else
                {
                    pair<int, int> temp1 = {dp[i][j - 1].first, a[j] + dp[i][j - 1].second};
                    pair<int, int> temp2 = {dp[i + 1][j].first, a[i] + dp[i + 1][j].second};
                    dp[i][j] = temp1.second > temp2.second ? temp1 : temp2;
                }
            }
        }
        fp = !fp;
    }
    return dp[0][n - 1].first;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    cout << maxscore(a, n);
}