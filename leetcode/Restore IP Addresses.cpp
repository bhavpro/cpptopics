#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> rec(string s, vector<string> parts, int i, int j)
{
    // base
    if (i == 0 && j == 0)
    {
        parts[0].push_back(s[0]);
        return rec(s, parts, i + 1, j);
    }
    if (i == s.size())
    {
        vector<string> ans;
        string a;
        for (int i = 0; i < 4; i++)
            a = a + parts[i] + ".";
        a.pop_back();
        ans.push_back(a);
        return ans;
    }

    // rec
    vector<string> ans1;
    char ele = s[i];
    parts[j].push_back(ele);
    int sint = stoi(parts[j]);
    if (sint <= 255 && sint >= 0)
        ans1 = rec(s, parts, i + 1, j);
    parts[j].pop_back();

    vector<string> ans2;
    if (j < 3)
    {
        parts[j + 1].push_back(ele);
        if (parts[j + 1][0] != '0')
            ans2 = rec(s, parts, i + 1, j + 1);
        parts[j + 1].pop_back();
    }

    vector<string> ans;
    merge(ans1.begin(), ans1.end(), ans2.begin(), ans2.end(), ans.begin());
    return ans;
}

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        return rec(s, vector<string>(4, ""), 0, 0);
    }
};