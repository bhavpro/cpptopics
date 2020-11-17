#include <bits/stdc++.h>

using namespace std;

vector<int> getss(vector<int> &a, int n)
{
    vector<int> ans;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();
        if (s.empty())
            ans[i] = i + 1;
        else
            ans[i] = i - s.top();
        s.push(i);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<int> ans = getss(a, n);
    for (int x : ans)
        cout << x << "\n";
    return 0;
}