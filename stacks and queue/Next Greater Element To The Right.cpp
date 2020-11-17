#include <bits/stdc++.h>

using namespace std;

vector<int> gng(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[i] >= s.top())
            s.pop();
        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;
    vector<int> ng = gng(arr, n);
    for (int x : ng)
        cout << x << "\n";
    return 0;
}