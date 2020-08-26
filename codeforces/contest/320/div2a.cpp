#include <bits/stdc++.h>

using namespace std;

int count(int x)
{
    int ans = 1;
    while (x > 1)
    {
        if (x & 1)
        {
            ans++;
            x--;
        }
        else
        {
            x >>= 1;
        }
    }
    return ans;
}
int main()
{
    int x;
    cin >> x;
    cout << count(x);
    return 0;
}