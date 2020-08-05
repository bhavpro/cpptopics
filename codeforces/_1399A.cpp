#include <bits/stdc++.h>

using namespace std;

bool ispossible(vector<int> &a, int n)
{
    sort(a.begin(), a.end());
    for (int i = 0; i < (n - 1); i++)
    {
        if ((a[i + 1] - a[i]) > 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            int x ;
            cin >> x;
            a[i] = x;
        }
        cout << (ispossible(a, n) ? "YES " : "NO ") << "\n";
    }
    return 0;
}