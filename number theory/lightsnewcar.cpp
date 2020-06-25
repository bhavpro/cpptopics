#include <iostream>
#include <string>

using namespace std;

int modder = 1000000009;

int strtoint(string a, int mod)
{
    long long mynum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        mynum *= 10;
        mynum += (a[i] - '0');
        mynum %= mod;
    }
    return mynum;
}

int fastpower(int a, int b)
{
    // base
    if (b == 0)
    {
        return 1;
    }

    if (b == 1)
    {
        return a;
    }

    // rec
    int x = fastpower(a, b / 2);
    long long ans = ((long long)x * x) % modder;

    if (b & 1 == 1) // odd
    {
        ans = (ans * a) % modder;
    }

    return ans;
}

int price(string A, string B)
{
    int a = strtoint(A, modder);
    int b = strtoint(B, modder - 1);
    
    return fastpower(a, b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a;
        cin >> b;
        cout << price(a, b) << "\n";
    }
    return 0;
}