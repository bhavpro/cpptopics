#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

int getint(char s)
{
    if (s >= '0' && s <= '9')
    {
        return (s - '0');
    }

    if (s >= 'A' && s <= 'Z')
    {
        return (s - 'A') + 10;
    }

    if (s >= 'a' && s <= 'z')
    {
        return (s - 'a') + 36;
    }

    if (s == '-')
    {
        return 62;
    }
    return 63;
}

int get0(int num)
{
    int i = 6;
    int count = 0;
    while (i != 0)
    {
        if (!(num & 1))
        {
            count++;
        }
        num >>= 1;
        i--;
    }
    return count;
}

int getans(string s)
{
    long long count = 1;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int num = getint(s[i]);
        int num0 = get0(num);
        count = (count * pow(3, num0));
        count = count % mod;
    }
    return count;
}

int main()
{
    string s;
    cin >> s;
    cout << getans(s);
    return 0;
}