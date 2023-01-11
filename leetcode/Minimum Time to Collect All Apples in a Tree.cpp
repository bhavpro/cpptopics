#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{

    int gettime(unordered_map<int, vector<int>> &edgemap, vector<bool> &hasApple, int i = 0, int p = -1)
    {
        int time = 0;
        // base

        // rec
        for (int j = 0; j < edgemap[i].size(); j++)
            time += (edgemap[i][j] != p ? gettime(edgemap, hasApple, edgemap[i][j], i) : 0);
        if (!i)
            return time;
        if (time)
            return time + 1;
        if (!time && hasApple[i])
            return 1;
        return 0;
    }

public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        unordered_map<int, vector<int>> edgemap;
        for (int i = 0; i < edges.size(); i++)
        {
            edgemap[edges[i][0]].push_back(edges[i][1]);
            edgemap[edges[i][1]].push_back(edges[i][0]);
        }

        return gettime(edgemap, hasApple) << 1;
    }
};