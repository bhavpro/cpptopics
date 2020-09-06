#include <bits/stdc++.h>

using namespace std;

vector<int> allFactors(int A)
{
    vector<int> ans;
    set<int> s;
    for (int i = 1; i * (long long)i <= A; i++)
        if (A % i == 0)
        {
            s.insert(i);
            s.insert(A / i);
        }

    for (int x : s)
        ans.push_back(x);
    return ans;
}
