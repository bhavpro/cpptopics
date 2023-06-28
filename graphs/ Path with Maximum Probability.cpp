#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<int, double>>> g(n);
        for (int i = 0; i < edges.size(); i++)
        {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        const int inf = 1e9 + 7;
        vector<bool> visited(n + 1, false);
        vector<long double> distance(n + 1, inf);
        priority_queue<pair<long double, int>> pq;
        pq.push({1, start});
        while (!pq.empty())
        {
            pair<long double, int> p = pq.top();
            pq.pop();
            if (visited[p.second])
                continue;
            visited[p.second] = true;
            distance[p.second] = p.first;
            int i = -1;
            for (pair<int, double> &v : g[p.second])
            {
                if (!visited[v.first])
                {
                    pq.push({v.second * p.first, v.first});
                    continue;
                }
            }
        }
        return distance[end] != inf ? distance[end] : 0;
    }
};