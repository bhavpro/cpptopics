#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef vector<vector<int>> vvi;

#define ptoi(i, j, n) \
	{                 \
		n *i + j      \
	}
#define itopr(x, n) \
	{               \
		x / n       \
	}

#define itopc(x, n) \
	{               \
		x % n       \
	}

#define checkvalid(r, c, n) ((r == -1 || r == n || c == -1 || c == n) ? false : true)

#define dist(i, j, r, c) (abs(i - r) + abs(c - j))

int trav[] = {-1, +1};

class Solution
{

public:
	int maximumSafenessFactor(vector<vector<int>> &grid)
	{
		int n = grid.size();
		vvi md(n, vector<int>(n, -1));
		queue<int> q;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j])
				{
					q.push(ptoi(i, j, n));
					md[i][j] = 0;
				}
			}
		}

		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			int r = itopr(x, n), c = itopc(x, n);
			for (int i = 0; i <= 1; i++)
			{
				int rv = r + trav[i];
				int cv = c + trav[i];
				if (checkvalid(rv, c, n) && md[rv][c] == -1)
				{
					q.push(ptoi(rv, c, n));
					md[rv][c] = md[r][c] + 1;
				}
				if (checkvalid(r, cv, n) && md[r][cv] == -1)
				{
					q.push(ptoi(r, cv, n));
					md[r][cv] = md[r][c] + 1;
				}
			}
		}

		priority_queue<pair<int, int>> pq;
		pq.push({md[0][0], 0});

		vvi vis(n, vector<int>(n, 0));

		while (!pq.empty())
		{
			pair<int, int> p = pq.top();
			int v = p.first;
			int x = p.second;
			pq.pop();
			int r = itopr(x, n), c = itopc(x, n);
			vis[r][c] = 1;
			md[r][c] = min(v, md[r][c]);
			v = md[r][c];
			if (r == n - 1 && c == n - 1)
				return md[r][c];

			for (int i = 0; i <= 1; i++)
			{
				int rv = r + trav[i];
				int cv = c + trav[i];
				if (checkvalid(rv, c, n) && !vis[rv][c])
				{
					pq.push({v, ptoi(rv, c, n)});
				}
				if (checkvalid(r, cv, n) && !vis[r][cv])
				{
					pq.push({v, ptoi(r, cv, n)});
				}
			}
		}
		return md[n - 1][n - 1];
	}
};

int main()
{
	vvi grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
	Solution s;
	s.maximumSafenessFactor(grid);
}