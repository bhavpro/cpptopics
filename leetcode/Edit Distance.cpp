#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> ans(m + 1, vector<int>(n + 1, 1e9));
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0)
                    ans[0][j] = j;
                else if (j == 0)
                    ans[i][0] = i;
                else
                {
                    // replace
                    int a1 = ans[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1);

                    // del
                    int a2 = ans[i - 1][j] + 1;

                    // add
                    int a3 = ans[i][j - 1] + 1;

                    ans[i][j] = min(min(a1, a2), a3);
                }
            }
        }
        return ans[m][n];
    }
};