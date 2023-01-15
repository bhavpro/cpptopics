#include <vector>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> sum(triangle.size(), vector<int>(triangle.size(), -1));
        for (int i = triangle.size() - 1; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                if (i == (triangle.size() - 1))
                    sum[i][j] = triangle[i][j];
                else
                    sum[i][j] = min(sum[i + 1][j], sum[i + 1][j + 1]) + triangle[i][j];

        return sum[0][0];
    }
};