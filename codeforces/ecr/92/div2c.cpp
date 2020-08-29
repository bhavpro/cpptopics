#include <bits/stdc++.h>

using namespace std;

string getorig(string s, int n, int x)
{
    string w(n, '-');
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            if (i - x >= 0)
            {
                if (w[i - x] == '1')
                    return "-1";

                w[i - x] = '0';
            }
            if (i + x < n)
            {
                if (w[i + x] == '1')
                    return "-1";

                w[i + x] = '0';
            }
        }
        else // s[i] == '1'
        {
            if (i - x >= 0 && w[i - x] != '0')
            {
                w[i - x] = '1';
            }
            else if (i + x < n && w[i + x] != '0')
            {
                w[i + x] = '1';
            }
            else
                return "-1";
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (w[i] == '-')
            w[i] = '1';
    }
    return w;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int x;
        cin >> x;
        int n = s.size();
        cout << getorig(s, n, x) << "\n";
    }
    return 0;
}