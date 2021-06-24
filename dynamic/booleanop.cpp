#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> noofwaystotrueandfalse(vector<char> &vchar, vector<char> &sym)
{

    vector<pair<int, int>> dp(vchar.size(), make_pair(0, 0));
    bool and_ = false, or_ = false, xor_ = false;
    for (int i = 0; i < sym.size(); i++)
    {
        if (sym[i] == '^')
            xor_ = true;
        if (sym[i] == '&')
            and_ = true;
        if (sym[i] == '|')
            or_ = true;
    }

    for (int i = 0; i < vchar.size(); i++)
    {
        if (i == 0)
            if (vchar[0] == 'T')
                dp[0] = {1, 0};
            else
                dp[0] = {0, 1};
        else
        {
            pair<int, int> prev = dp[i - 1];
            if (xor_)
            {
                if (vchar[i] == 'T')
                {
                    dp[i].first += (prev.second);
                    dp[i].second += (prev.first);
                }
                else
                {
                    dp[i].first += (prev.first);
                    dp[i].second += (prev.second);
                }
            }
            if (and_)
            {
                if (vchar[i] == 'T')
                {
                    dp[i].first += (prev.first);
                    dp[i].second += (prev.second);
                }
                else
                    dp[i].second += (prev.first + prev.second);
            }
            if (or_)
            {
                if (vchar[i] == 'T')
                    dp[i].first += (prev.first + prev.second);
                else
                {
                    dp[i].first += (prev.first);
                    dp[i].second += (prev.second);
                }
            }
        }
    }

    return *prev(dp.end());
}

int main()
{
    vector<char> vchar;
    vector<char> sym;
    int cc, cs;
    cin >> cc >> cs;
    char ch;
    for (int i = 0; i < cc; i++)
    {
        cin >> ch;
        vchar.push_back(ch);
    }
    for (int i = 0; i < cs; i++)
    {
        cin >> ch;
        sym.push_back(ch);
    }
    pair<int, int> p = noofwaystotrueandfalse(vchar, sym);
    cout << "\n"
         << p.first << " " << p.second;
    return 0;
}