#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        // int *a = new int[n];
        unordered_map<int, int> a;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[x]++;
            if (a[x] == 2)
            {
                count++;
            }
        }
        if (a.size() <= 1)
        {
            cout << 0 << "\n";
            continue;
        }
        cout << n / count << "\n";
        // delete[] a;
    }
    return 0;
}