#include <bits/stdc++.h>

using namespace std;

int mintime(vector<string> arr, int r, int c)
{
    vector<pair<pair<int, int>, pair<int, int>>> dp(r);
    for (int i = r - 1; i >= 0; i--)
    {
        string s = arr[i];
        int fi = c, li = -1;
        for (int i = 0; i < c; i++)
            if (s[i] == '1')
            {
                fi = i;
                break;
            }
        for (int i = c - 1; i >= 0; i--)
            if (s[i] == '1')
            {
                li = i;
                break;
            }

        if (i == r - 1)
        {
            if (fi == c)
            {
                dp[i].first = {0, 0};
                dp[i].second = {0, 0};
            }
            else
            {
                dp[i].first = {li, li};
                dp[i].second = {li, li};
            }
        }
        else
        {
            // get to next floor stairs
            pair<int, int> p1 = dp[i + 1].first, p2 = dp[i + 1].second;
            dp[i].first = {min(p1.second + p1.first, p2.second + p2.first) + 1, 0};
            dp[i].second = {c - 1 + min(p1.first - p1.second, p2.first - p2.second) + 1, c - 1};

            // get to end room
            if (fi != c)
            {
                dp[i].first = {dp[i].first.first + li, li};
                dp[i].second = {dp[i].second.first + (c - 1 - fi), fi};
            }
        }
    }
    return min(dp[0].first.first, dp[0].second.first);
}

int main()
{
    int r, c;
    cin >> r >> c;
    c += 2;
    vector<string> arr;
    bool top = false;
    for (int i = 0; i < r; i++)
    {
        string str;
        cin >> str;
        if (top == false)
        {
            bool all0 = true;
            for (char x : str)
            {
                if (x == '1')
                {
                    all0 = false;
                    break;
                }
            }
            if (all0 == true)
                continue;
            top = true;
        }
        arr.push_back(str);
    }
    r = arr.size();
    if (r == 0)
        cout << 0;
    else
        cout << mintime(arr, r, c);
}