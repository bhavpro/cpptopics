#include <bits/stdc++.h>

using namespace std;

string pokemon[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main()
{
    bitset<8> inc;
    inc.set();
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < 8; i++)
    {
        if (pokemon[i].size() != n)
        {
            inc[i] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '.')
        {
            for (int j = 0; j < 8; j++)
            {
                if (inc[j] != 0)
                    if (pokemon[j][i] != s[i])
                    {
                        inc[j] = 0;
                    }
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (inc[i] == 1)
        {
            cout << pokemon[i];
            break;
        }
    }
    return 0;
}