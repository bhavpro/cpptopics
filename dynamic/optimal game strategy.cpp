#include <bits/stdc++.h>

using namespace std;

#define intpair pair<int, int>

intpair memo[20][20];

intpair rec(vector<int> &a, int s, int e, bitset<1> turn) // A - 1   B - 0
{
    // base
    if (s + 1 == e)
    {
        memo[s][e] = {max(a[s], a[e]), min(a[s], a[e])};
        return memo[s][e];
    }

    // rec
    auto p1 = memo[s + 1][e] == make_pair(-1, -1) ? rec(a, s + 1, e, !turn[0]) : memo[s + 1][e];
    auto p2 = memo[s][e - 1] == make_pair(-1, -1) ? rec(a, s, e - 1, !turn[0]) : memo[s][e - 1];
    memo[s + 1][e] = p1;
    memo[s][e - 1] = p2;

    if (turn[0] == 1) // A turn
    {

        p1.first += a[s];
        p2.first += a[e];
        if (p1.first > p2.first)
            return p1;
        return p2;
    }
    else // B turn
    {
        p1.second += a[s];
        p2.second += a[e];
        if (p1.second < p2.second)
            return p1;
        return p2;
    }
}

void pairintdpchecker(vector<int> a, intpair dp[30][30])
{
    cout << "\n\n";
    cout << "   ";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "    ";
    }
    cout << "\n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
        for (int j = 0; j < a.size(); j++)
        {
            cout << dp[i][j].first << "," << dp[i][j].second << "  ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}
int dp(vector<int> &a)
{
    intpair dp[30][30];
    bool turn = !(a.size() & 1);
    for (int j = 1; j < a.size(); j++)
    {
        int k = j - 1;
        for (int i = 0; i < a.size() - j; i++)
        {
            k++;
            int s = i, e = k;
            if (s + 1 == e)
            {
                dp[s][e] = {max(a[s], a[e]), min(a[s], a[e])};
                continue;
            }
            intpair p1 = dp[s][e - 1];
            intpair p2 = dp[s + 1][e];
            if (turn == true) // A turn
            {
                p1.first += a[e];
                p2.first += a[s];
                if (p1.first > p2.first)
                {
                    dp[s][e] = p1;
                }
                else
                {
                    dp[s][e] = p2;
                }
            }
            else // B turn
            {
                cout << i << k << turn << "\n";
                p1.second += a[e];
                p2.second += a[s];
                if (p1.second < p2.second)
                {
                    dp[s][e] = p1;
                }
                else
                {
                    dp[s][e] = p2;
                }
                if (i == 1 && j == 3)
                {
                    cout << dp[1][3].first << dp[1][3].second;
                }
            }
        }
        turn = !turn;
    }
    pairintdpchecker(a, dp);
    return dp[0][a.size() - 1].first;
}

int main()
{
    vector<int> arr(4);
    arr[0] = 4;
    arr[1] = 9;
    arr[2] = 3;
    arr[3] = 7;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            memo[i][j] = make_pair(-1, -1);
        }
    }
    bitset<1> b;
    b.set();
    cout << dp(arr);
    return 0;
}