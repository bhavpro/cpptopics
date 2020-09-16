#include <bits/stdc++.h>

using namespace std;

long long convto10(string &str, int b)
{
    int power = 1;
    long long ans = 0;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        int val;
        if (str[i] >= 'A')
        {
            val = str[i] - 'A' + 10;
        }
        else
        {
            val = str[i] - '0';
        }
        ans += (val * power);
        power *= b;
    }
    return ans;
}

string convfrom10(long long &base10, int b)
{
    string ans;
    while (base10 > 0)
    {
        int mod = base10 % b;
        base10 /= b;
        if (mod >= 10)
        {
            mod -= 10;
            ans = (char)(mod + 'A') + ans;
        }
        else
        {
            ans = (char)(mod + '0') + ans;
        }
    }
    return ans;
}

string changeBase(string numAsString, int b1, int b2)
{
    if (b1 == 10 && b2 == 10)
        return numAsString;
    long long base10 = convto10(numAsString, b1);
    return convfrom10(base10, b2);
}