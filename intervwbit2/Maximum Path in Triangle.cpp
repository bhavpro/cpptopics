#include <vector>
using namespace std;

int solve(vector<vector<int>> &A)
{
    int n = A.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    ans[0][0] = A[0][0];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            ans[i + 1][j] = max(ans[i][j] + A[i + 1][j], ans[i + 1][j]);
            ans[i + 1][j + 1] = max(ans[i][j] + A[i + 1][j + 1], ans[i + 1][j + 1]);
        }
    }
    int aa = 0;
    for (int i = 0; i < n; i++)
        aa = max(aa, ans[n - 1][i]);
    return aa;
}
