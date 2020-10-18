#include <bits/stdc++.h>

using namespace std;

int main()
{
    int dp[5] = {};
    vector<int> a({4, 2, 5, 7, 2});
    cout << find(a.begin(), a.end(), 7) - a.begin();
}