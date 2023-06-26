#include <vector>
using namespace std;

const int intmax = 1e9 + 7;
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        // create adj matrix
        vector<vector<int>> adm(n, vector<int>(n, intmax));
        for (vector<int> &edge : edges)
        {
            adm[edge[0]][edge[1]] = edge[2];
            adm[edge[1]][edge[0]] = edge[2];
        }
        for (int i = 0; i < n; i++)
            adm[i][i] = 0;

        // floyd warshall
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    if (i == k || j == k || i == j)
                        continue;
                    if (adm[i][k] + adm[k][j] < adm[i][j])
                        adm[i][j] = adm[i][k] + adm[k][j];
                }
        }

        vector<int> ct(n, 0);
        int i = 0;
        int minval = intmax;
        for (vector<int> &v : adm)
        {
            for (int x : v)
            {
                if (x != 0 && x <= distanceThreshold)
                    ct[i]++;
            }
            minval = min(minval, ct[i]);
            i++;
        }

        for (int i = n - 1; i >= 0; i--)
            if (ct[i] == minval)
                return i;
        
        return n-1;
    }
};