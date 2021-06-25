#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool operate(char c1, char c2, char s = '^')
{
    bool b1 = (c1 == 'T' ? 1 : 0);
    bool b2 = (c2 == 'T' ? 1 : 0);
    if (s == '&')
        return b1 & b2;
    if (s == '|')
        return b1 | b2;
    if (s == '^')
        return b1 ^ b2;
    return false;
}

int counttrue(char *charr, char *sym, int cc)
{
    vector<pair<int, int>> dp(cc, {0, 0});
    for (int i = 0; i < cc; i++)
    {
        if (i == 0)
        {
            if (charr[0] == 'T')
                dp[0] = {1, 0};
            else
                dp[0] = {0, 1};
            continue;
        }
        if (i == 1)
        {
            if (operate(charr[0], charr[1], sym[0]))
                dp[1] = {1, 0};
            else
                dp[1] = {0, 1};
            continue;
        }
        // else
        dp[i] = {0, 0};
        char part1 = (operate(charr[i], charr[i - 1], sym[i - 1]) == 1 ? 'T' : 'F');
        if (operate('T', part1, sym[i - 2]))
            dp[i] = make_pair(dp[i].first + dp[i - 2].first, dp[i].second);
        else
            dp[i] = make_pair(dp[i].first, dp[i].second + dp[i - 2].first);
        if (operate('F', part1, sym[i - 2]))
            dp[i] = make_pair(dp[i].first + dp[i - 2].second, dp[i].second);
        else
            dp[i] = make_pair(dp[i].first, dp[i].second + dp[i - 2].second);

        if (operate('T', charr[i], sym[i - 1]))
            dp[i] = make_pair(dp[i].first + dp[i - 1].first, dp[i].second);
        else
            dp[i] = make_pair(dp[i].first, dp[i].second + dp[i - 1].first);
        if (operate('F', charr[i], sym[i - 1]))
            dp[i] = make_pair(dp[i].first + dp[i - 1].second, dp[i].second);
        else
            dp[i] = make_pair(dp[i].first, dp[i - 1].second + dp[i].second);
        // changed
        for (int j = 0; j < i; j++)
        {
        }
    }

    int ans = dp[cc - 1].first;
    return ans;
}

typedef pair<int, int> pii;

pii operateit(pii a, pii b, char sym)
{
    pii ans;
    int t1 = a.first, t2 = b.first, f1 = a.second, f2 = b.second;
    if (sym == '|')
        ans = {t1 * t2 + t1 * f2 + t2 * f1, f1 * f2};

    if (sym == '&')
        ans = {t1 * t2, t1 * f2 + t2 * f1 + f1 * f2};

    if (sym == '^')
        ans = {t1 * f2 + t2 * f1, t1 * t2 + f1 * f2};

    return ans;
}

int counttruenew(char *charr, char *sym, int cc)
{
    vector<vector<pair<int, int>>> dp(cc, vector<pair<int, int>>(cc));
    for (int k = 0; k < cc; k++)
    {

        for (int i = 0, j = k; j < cc; i++, j++)
        {
            if (k == 0)
            {
                dp[i][j] = (charr[i] == 'T' ? make_pair(1, 0) : make_pair(0, 1));
                continue;
            }
            // else
            dp[i][j] = {0, 0};
            for (int x = i; x < j; x++)
            {
                pair<int, int> l = dp[i][x];
                pair<int, int> r = dp[x + 1][j];
                pair<int, int> at = operateit(l, r, sym[x]);
                dp[i][j] = {dp[i][j].first + at.first, dp[i][j].second + at.second};
            }
        }
    }
    return dp[0][cc - 1].first;
}

int main()
{
    int cc;
    cin >> cc;
    char *charr = new char[cc];
    char *sym = new char[cc - 1];

    for (int i = 0; i < cc; i++)
        cin >> charr[i];

    for (int i = 0; i < cc - 1; i++)
        cin >> sym[i];

    cout << counttruenew(charr, sym, cc);

    delete[] charr;
    delete[] sym;
    return 0;
}