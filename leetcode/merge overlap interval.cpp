#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortit(const vector<int> &a, const vector<int> &b)
{
	return a[0] < b[0];
}

class Solution
{
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals)
	{
		sort(intervals.begin(), intervals.end(), sortit);
		vector<vector<int>> ans(1, intervals[0]);
		int j = 0;
		int n = intervals.size();
		for (int i = 1; i < n; i++)
		{
			if (ans[j][1] >= intervals[i][0])
				ans[j][1] = max(ans[j][1], intervals[i][1]);
			else
			{
				ans.push_back(intervals[i]);
				j++;
			}
		}
		return ans;
	}
};