#include <vector>
using namespace std;

int minPathSum(vector<vector<int>> &A)
{
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> sum(m, vector<int>(n, 1e9 + 7));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                sum[i][j] = A[i][j];
            else if (i == 0)
                sum[i][j] = sum[i][j - 1] + A[i][j];
            else if (j == 0)
                sum[i][j] = sum[i - 1][j] + A[i][j];
            else
                sum[i][j] = min(sum[i - 1][j] + A[i][j], sum[i][j - 1] + A[i][j]);
        }
    }
    return sum[m - 1][n - 1];
}
