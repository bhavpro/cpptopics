#include <bits/stdc++.h>

using namespace std;

string convertToTitle(int A)
{
    string ans;
    while (A != 0)
    {
        A--;
        int rem = A % 26;
        A = A / 26;
        ans = (char)('A' + rem) + ans;
    }
    return ans;
}

int main()
{
    int a;
    cin >> a;
    cout << convertToTitle(a);
}