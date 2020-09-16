#include <bits/stdc++.h>

using namespace std;

string addStrings(string s1, string s2)
{
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    int c = 0;
    string ans = "";
    while (i >= 0 && j >= 0)
    {
        int a = s1[i] - '0';
        int b = s2[j] - '0';
        i--;
        j--;
        int sum = a + b + c;
        c = 0;
        if (sum > 9)
        {
            sum %= 10;
            c = 1;
        }
        ans = ((char)(sum + '0')) + ans;
    }

    while (i >= 0)
    {
        int a = s1[i] - '0';
        i--;
        int sum = a + c;
        c = 0;
        c = sum / 10;
        sum %= 10;
        ans = (char)(sum + '0') + ans;
    }

    while (j >= 0)
    {
        int b = s2[j] - '0';
        j--;
        int sum = b + c;
        c = sum / 10;
        sum %= 10;
        ans = (char)(sum + '0') + ans;
    }

    if (c == 1)
    {
        ans = "1" + ans;
    }
    return ans;
}