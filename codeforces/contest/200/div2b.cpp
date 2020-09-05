#include <bits/stdc++.h>

using namespace std;

int geti(int a, int b)
{
    int c = min(a, b);
    int d = max(a, b);
    if (c == 1)
    {
        if (d == 2)
        {
            return 1;
        }
        else
            return 3;
    }
    else
        return 2;
}

int solve(int a, int b, int c)
{
    set<pair<int, int>> s;
    s.insert({a, 1});
    s.insert({b, 2});
    s.insert({c, 3});
    int arr[3] = {0, 0, 0};
    while (s.size() > 1)
    {
        auto beg = s.begin();
        auto end = prev(s.end());
        pair<int, int> st, en;
        st = *beg;
        en = *end;
        s.erase(beg);
        s.erase(end);
        int i = geti(st.second, en.second);
        arr[i - 1]++;
        st.first--;
        en.first--;
        if (st.first != 0)
        {
            s.insert(st);
        }
        if (en.first != 0)
        {
            s.insert(en);
        }
    }
    if (s.empty())
    {
        cout << arr[0] << " " << arr[1] << " " << arr[2];
        return 0;
    }
    else
        return -1;
}

int solve2(int a, int b, int c)
{
    if ((a + b + c) & 1)
        return -1;

    int x = a + b - c;
    if (x < 0)
        return -1;
    x >>= 1;
    int y = b + c - a;
    if (y < 0)
        return -1;
    y >>= 1;
    int z = a + c - b;
    if (z < 0)
        return -1;
    z >>= 1;
    cout << x << " " << y << " " << z;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int x = solve2(a, b, c);
    if (x == -1)
        cout << "Impossible";
    return 0;
}