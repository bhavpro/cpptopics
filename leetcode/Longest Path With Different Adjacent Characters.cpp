#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{

    pair<int, int> lp(const vector<vector<int>> &g, const string &s, int cur = 0, int par = -1)
    {
        vector<int> arr1, arr2;
        arr1.push_back(0);
        arr1.push_back(0);
        arr2.push_back(0);
        arr2.push_back(0);

        for (int ch : g[cur])
            if (ch != par)
            {
                pair<int, int> p = lp(g, s, ch, cur);
                arr2.push_back(p.second);
                if (s[cur] != s[ch])
                    arr1.push_back(p.first + 1);
            }

        pair<int, int> ans = {0, 0};

        // arr.second is max len in cur subtree
        // max width or max h1 + max h2
        int mw = 0;
        for (int i = 0; i < arr2.size(); i++)
            if (arr2[mw] < arr2[i])
                mw = i;

        int mh1 = 0;
        for (int i = 0; i < arr1.size(); i++)
            if (arr1[mh1] < arr1[i])
                mh1 = i;

        int mh2 = 1;
        for (int i = 0; i < arr1.size(); i++)
            if (i != mh1 && arr1[mh2] < arr1[i])
                mh2 = i;

        ans.second = max(arr2[mw], arr1[mh1] + arr1[mh2]);
        ans.first = arr1[mh1];
        return ans;
    }

public:
    int longestPath(vector<int> &parent, string s)
    {
        vector<vector<int>> child(parent.size());
        for (int i = 1; i < parent.size(); i++)
            child[parent[i]].push_back(i);
        return lp(child, s).second + 1;
    }
};

int main()
{
    vector<int> p = {-1, 0, 0, 1, 1, 2};
    string s = "abacbe";
    Solution a;
    cout << a.longestPath(p, s);
    return 0;
}