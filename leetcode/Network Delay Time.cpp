#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <bitset>
using namespace std;

typedef pair<int, int> pii;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pii>> adj(n + 1);
        for (vector<int> &v : times)
            adj[v[0]].push_back(make_pair(v[1], v[2]));

        int maxi = 0;

        bitset<101> vis;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(make_pair(0, k));

        while (!pq.empty())
        {
            pii src = pq.top();
            pq.pop();
            if (!vis[src.second])
            {
                vis[src.second] = 1;
                maxi = max(maxi, src.first);

                for (pii p : adj[src.second])
                {
                    if (!vis[p.first])
                    {
                        pq.push({p.second + src.first, p.first});
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
            if (!vis[i])
                return -1;
        return maxi;
    }
};
