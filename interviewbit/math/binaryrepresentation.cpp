#include <bits/stdc++.h>

using namespace std;

string findDigitsInBinary(int A)
{
    if (A == 0)
        return "0";
    string ans;
    while (A != 0)
    {
        ans.push_back((A & 1) + '0');
        A >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
