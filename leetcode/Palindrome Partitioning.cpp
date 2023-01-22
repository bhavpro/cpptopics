#include <vector>
#include <string>

using namespace std;

bool palin(string &s)
{
    int n = s.size();
    for (int i = 0; i < (n >> 1); i++)
        if (s[i] != s[n - i - 1])
            return false;
    return true;
}

void rec(string s, vector<vector<string>> &sol, vector<string> &ta)
{
    // base
    if (s.size() == 0)
    {
        sol.push_back(ta);
        return;
    }


    // rec
    for (int i = 0; i < s.size(); i++)
    {
        string str = s.substr(0, i + 1);
        if (palin(str))
        {
            ta.push_back(str);
            rec(s.substr(i + 1, s.size() - (i + 1)), sol, ta);
            ta.pop_back();
        }
    }
}

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> sol;
        vector<string> ta;
        rec(s, sol, ta);
        return sol;
    }
};