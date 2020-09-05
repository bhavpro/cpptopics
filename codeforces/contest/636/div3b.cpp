#include <bits/stdc++.h>
using namespace std;

void create(int n)
{
    int mid = n >> 1;
    int num = 2;
    bool x = 0;
    for (int i = 1; i <= mid; i++)
    {
        cout << num << " ";
        x = !x;

        num += 2;
        if (x == 0)
            num += 2;
    }

    num = 2;
    x = 0;
    for (int i = 1; i <= mid; i++)
    {
        if (x == 0)
            cout << num - 1 << " ";
        else
            cout << num + 1 << " ";
        x = !x;

        num += 2;
        if (x == 0)
            num += 2;
    }
}

void create2(int n)
{
    int mid = n >> 1;
    int num = 2;
    int sume = 0;
    for (int i = 1; i <= mid; i++)
    {
        cout << num << " ";
        sume += num;
        num += 2;
    }

    num = 1;
    int sumo = 0;
    for (int i = 1; i < mid; i++)
    {
        cout << num << " ";
        sumo += num;
        num += 2;
    }
    cout << sume - sumo;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if ((n >> 1) & 1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            create2(n);
            cout << "\n";
        }
    }

    return 0;
}