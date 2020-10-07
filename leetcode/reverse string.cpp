#include <bits/stdc++.h>

using namespace std;

void reverseString(vector<char> &s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        char x = s[l];
        s[l] = s[r];
        s[r] = x;
        l++;
        r--;
    }
}