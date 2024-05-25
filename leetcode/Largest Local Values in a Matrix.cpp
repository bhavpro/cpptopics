#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
	vector<vector<int>> largestLocal(vector<vector<int>> &grid)
	{
		int n = grid.size();
		vector<vector<int>> temp(n - 2, vector<int>(n - 2));
		for (int i = 0; i < n - 2; i++)
		{
			for (int j = 0; j < n - 2; j++)
			{
  				for (int k = 0; k < 3; k++)
					for (int l = 0; l < 3; l++)
						maxv = max(maxv, grid[i + k][j + l]);
				temp[i][j] = maxv;
			}
		}

		return temp;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> v;
	v = {
		{9, 9, 8, 1},
		{5, 6, 2, 6},
		{8, 2, 6, 4},
		{6, 2, 2, 2}};
	s.largestLocal(v);
	return 0;
}