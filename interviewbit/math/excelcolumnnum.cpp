#include <bits/stdc++.h>

using namespace std;

int titleToNumber(string A)
{
    int num = 0;
    int power = 1;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        num += power * (A[i] - 'A' + 1);
        power *= 26;
    }

    return num;
}

int main()
{
    string a;
    cin >> a;
    cout << titleToNumber(a);
}