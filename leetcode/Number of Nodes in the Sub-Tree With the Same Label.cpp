#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{

    unordered_map<char, int> getcount(const vector<vector<int>> &g, const string &labels, vector<int> &ans, int cur = 0, int parent = -1)
    {
        unordered_map<char, int> labelcount;
        for (int child : g[cur])
            if (child != parent)
            {
                unordered_map<char, int> curlabel = getcount(g, labels, ans, child, cur);
                // add curlabel to labelcount
                for (pair<char, int> temp : curlabel)
                    labelcount[temp.first] += temp.second;
            }

        labelcount[labels[cur]]++;
        ans[cur] = labelcount[labels[cur]];

        return labelcount;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        vector<vector<int>> g(n);
        for (int i = 0; i < edges.size(); i++)
            for (int j = 0; j < 2; j++)
                g[edges[i][j]].push_back(edges[i][1 - j]);

        vector<int> ans(n, 0);
        getcount(g, labels, ans);
        return ans;
    }
};