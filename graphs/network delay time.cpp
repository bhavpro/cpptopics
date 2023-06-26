#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // create a vector graph
        vector<vector<pair<int, int>>> g(n + 1);
        for (vector<int> &e : times)
        {
            g[e[0]].push_back({e[1], e[2]});
        }

        // bfs
        vector<int> dist(n + 1, 1e9 + 7);
        dist[0] = 0;
        set<pair<int, int>> s; // mindist,vert
        s.insert({0, k});
        while (!s.empty())
        {
            int minval = s.begin()->first;
            int minvert = s.begin()->second;
            s.erase(s.begin());
            dist[minvert] = min(minval,dist[minvert]);

            for (pair<int, int> p : g[minvert])
                if (dist[p.first] == 1e9 + 7)
                    s.insert({p.second + minval, p.first});
        }

        int maxv = 0;
        for (int x : dist)
        {
            if (x == 1e9 + 7)
                return -1;
            maxv = max(maxv, x);
        }
        return maxv;
    }
};

int main()
{
    vector<vector<int>> times = {{1,2,1}, {2, 3, 2}, {1,3,2}};
    int n = 3, k = 1;
    Solution a;
    a.networkDelayTime(times, n, k);
}