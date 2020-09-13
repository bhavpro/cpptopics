#include <bits/stdc++.h>

using namespace std;

bitset<10000> b;

vector<int> findPerm(const string A, int B)
{
    vector<int> a(A.size() + 1);
    int newstart = 1000;
    int start = newstart;
    int cur = 1;
    int j = 0;
    for (int i = 0; i <= A.size(); i++)
    {
        a[i] = start;
        int addon = i - j + 1;
        if (i == A.size() || A[i] == 'I')
        {
            for (; j <= i; j++)
            {
                a[j] = a[j] - start + cur;
            }
            cur += addon;
        }
        start--;
    }
    return a;
}

vector<int> afindPerm(const string a, int B) {
    vector<int> s;
    int n = B;
    vector<int> ans(n+1);
    for (int i = 0; i <= n; i++)
        s.push_back(i + 1);
        
    int mini = 0;
    int maxi = n;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'I')
        {
            ans[i] = s[mini];
            mini++;
        }
        else
        {
            ans[i] = s[maxi];
            maxi--;
        }
    }
    ans[n] = s[mini];
    return ans;
}
