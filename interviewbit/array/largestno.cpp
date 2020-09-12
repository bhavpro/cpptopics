#include <bits/stdc++.h>

using namespace std;

bool mycompare(const string &a, const string &b)
{
    if (a == b)
        return true;

    int i = 0;
    while (a[i] == b[i] && i < min(a.size(), b.size()))
        i++;

    if (i == a.size())
        return b[i] <= b[i - 1];

    if (a == "9998" && b == "999")
        cout << (a[i] >= a[i - 1]);
    if (i == b.size())
        return a[i] < a[i - 1];

    return a[i] >= b[i];
}

string largestNumber(const vector<int> &A)
{
    vector<string> s;
    int if0 = 0;
    for (int x : A)
    {
        if (!x)
            if0++;
        stringstream ss;
        ss << x;
        s.push_back(ss.str());
    }
    if (if0 == A.size())
        return "0";
    sort(s.begin(), s.end(), mycompare);
    string ans = "";
    for (string str : s)
        ans += str;
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << largestNumber(a);
}