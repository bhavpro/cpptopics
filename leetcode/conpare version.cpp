#include <string>
using namespace std;
typedef long long ll;

class Solution
{
public:
	int compareVersion(string version1, string version2)
	{
		version1.push_back('.');
		version2.push_back('.');

		ll v1;
		int i = 0, ni = version1.size(), xi = 0;
		int j = 0, nj = version2.size(), xj = 0;

		while (i < max(ni, nj))
		{
			if (i < ni)
			{
				char chi = version1[i];
				if (chi == '.')
				{
					v1`.push_back(xi);
					xi = 0;
				}
				else
					xi = xi * 10 + (chi - '0');
			}

			if (i < nj)
			{
				char chj = version2[i];
				if (chj == '.')
				{
					v2.push_back(xj);
					xj = 0;
				}
				else
					xj = xj * 10 + (chj - '0');
			}
			i++;
		}

		ni = v1.size();
		nj = v2.size();

		for (int i = 0; i < max(ni, nj); i++)
		{
			if (i < ni && i < nj)
			{
				if (v1[i] > v2[i])
					return 1;
				if (v1[i] < v2[i])
					return -1;
			}
			else if (i < ni)
			{
				if (v1[i] > 0)
					return 1;
			}
			else
			{
				if (v2[i] > 0)
					return -1;
			}
		}
		return 0;
	}
};

int main()
{
	string v1, v2;
	v1 = "1.2";
	v2 = "1.10";
	Solution s;
	cout << s.compareVersion(v1, v2);
	return 0;
}