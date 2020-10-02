#include <bits/stdc++.h>

using namespace std;

namespace bha
{
    class trip
    {
    public:
        int v, r, c;
    };
    trip max(trip &a, trip &b)
    {
        if (a.v > b.v)
            return a;
        else if (a.v < b.v)
            return b;
        else if (a.r < b.r)
            return a;
        else
            return b;
    }

}; // namespace bha

using namespace bha;

vector<int> solve(int A, vector<int> &B)
{
    int n = B.size();
    vector<vector<trip>> dp(n + 1, vector<trip>(A + 1, {0, -1, -1}));
    unordered_map<int, int> ind;
    ind[B[0]] = 0;
    for (int i = 1; i < B.size(); i++)
    {
        if (ind[B[i]] == 0 && B[i] != B[0])
            ind[B[i]] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= A; j++)
        {
            if (B[i] > j)
                dp[i][j] = dp[i - 1][j];
            else if (B[i - 1] == j)
            {
                trip temp = {1, i, 0};
                dp[i][j] = max(temp, dp[i - 1][j]);
            }
            else
            {
                trip bb = {dp[i][j - B[i - 1]].v + 1, i, j - B[i - 1]};
                trip bn = {dp[i - 1][j - B[i - 1]].v + 1, i - 1, j - B[i - 1]};
                dp[i][j] = max(bb, bn);
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
    }
cout << dp[n][A].v;
    multiset<int> ctv;
    trip temp = dp[n][A];
    while (temp.r != -1 && temp.c != -1)
    {
        cout << temp.v << " " << temp.r << " " << temp.c << " \n"
             << flush;
        trip newtemp = dp[temp.r][temp.c];
        ctv.insert(ind[temp.c - newtemp.c]);
        temp = newtemp;
    }

    vector<int> ans;
    for (int x : ctv)
        ans.push_back(x);
    return ans;
}

int main()
{
    int p = 11;
    vector<int> a({8, 8, 6, 5, 4});
    vector<int> an = solve(p, a);
    for (int x : an)
        cout << x << " , ";
}