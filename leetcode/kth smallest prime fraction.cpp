#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct triplet
{
	double a;
	int x, y;

	bool operator>(const triplet &a) const
	{
		return this->a > a.a;
	}
};

class Solution
{
public:
	vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
	{
		int tn = sqrt(k << 1);
		while (tn * tn-- >= k)
			;
		int s = 0, e = arr.size() - 1 - tn;
		int n = tn + 1;
		n = n * (n + 1);
		n >>= 1;
		n = k - n;

		priority_queue<triplet, vector<triplet>, greater<triplet>> minheap;

		while (e < arr.size() - 1)
		{
			double d = (double)arr[s] / arr[e];
			minheap.push({d, arr[s], arr[e]});
			if (minheap.size() > n)
				minheap.pop();
			s++;
			e++;
			n--;
		}

		triplet tans;
		while (!minheap.empty())
		{
			tans = minheap.top();
			minheap.pop();
		}

		vector<int> ans(2);
		ans[0] = tans.x;
		ans[1] = tans.y;
		return ans;
	}
};

int main()
{
	vector<int> v({1, 2, 3, 5});
	int k = 3;
	Solution s;
	s.kthSmallestPrimeFraction(v, k);
}