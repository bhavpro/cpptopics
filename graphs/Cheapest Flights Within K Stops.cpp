#include <vector>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> dist(n, 1e9 + 7);
        dist[src] = 0;

        for (int j = 0; j <= k; j++)
        {
            vector<int> prevdist = dist;
            for (vector<int> &v : flights)
            {
                int s = v[0], d = v[1], di = v[2];
                if (prevdist[s] != (1e9 + 7) && (prevdist[s] + di) < dist[d])
                    dist[d] = prevdist[s] + di;
            }
        }
        return dist[dst] == (1e9 + 7) ? -1 : dist[dst];
    }
};