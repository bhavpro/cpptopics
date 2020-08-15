#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> intpair;

intpair solve(int *a, int n)
{
    intpair ans = {0, 0};
    int s = 0, e = n - 1;
    bool turn = 0;
    for (int i = 0; i < n; i++)
    {
        int maxi = 0;
        if (s == e)
            maxi = a[s++];
        else if (a[s] > a[e])
            maxi = a[s++];
        else
            maxi = a[e--];

        if (!turn)
            ans.first += maxi;
        else
            ans.second += maxi;
        turn = !turn;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    intpair ans = solve(a, n);
    cout << ans.first << " " << ans.second;
}