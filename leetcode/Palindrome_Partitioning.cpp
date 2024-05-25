#include <vector>
#include <string>
using namespace std;

class Solution
{
    vector<vector<string>> ans;
    vector<vector<bool>> isp;

    bool checkp(int s, int m)
    {
        return isp[s][m];
    }

    void rec(string &s, vector<string> ta = vector<string>(), int b = 0)
    {
        // base
        if (b == s.size())
        {
            ans.push_back(ta);
            return;
        }

        // rec
        for (int i = b; i < s.size(); i++)
        {
            if (checkp(b, i))
            {
                ta.push_back(s.substr(b, i - b + 1));
                rec(s, ta, i+1);
                ta.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        ans = vector<vector<string>>();
        int n = s.size();
        isp = vector<vector<bool>>(n, vector<bool>(n));
        for (int i = 0; i < n; i++)
            for (int j = i, k = 0; j < n; j++, k++)
                if (j == k)
                    isp[k][j] = 1;
                else if (s[k] == s[j])
                    if (k + 1 == j)
                        isp[k][j] = 1;
                    else
                        isp[k][j] = isp[k + 1][j - 1];
                else
                    isp[k][j] = 0;

        rec(s);
        return ans;
    }
};