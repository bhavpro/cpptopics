#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int mindiff = 1e9;
int maxnum = 0;
vector<int> x;

void rec(vector<int> &cookies, vector<int> &child, int j, int mask)
{
    // base
    int leftchild = child.size() - __builtin_popcount(mask);
    int leftcookies = cookies.size() - j;
    if (leftchild > leftcookies)
        return;

    if (j == cookies.size())
    {

        int tmin = *min_element(child.begin(), child.end());
        int tmax = *max_element(child.begin(), child.end());
        for (int i : child)
            cout << i << " ";
        cout << "\n";
        if (mindiff > (tmax - tmin))
        {
            mindiff = tmax - tmin;
            maxnum = tmax;
        }
        return;
    }

    // rec
    for (int i = 0; i < child.size(); i++)
    {
        child[i] += cookies[j];
        rec(cookies, child, j + 1, mask | (1 << i));
        child[i] -= cookies[j];
    }
}

class Solution
{
public:
    int distributeCookies(vector<int> &cookies, int k)
    {
        mindiff = 1e9;
        maxnum = 0;
        vector<int> child(k, 0);
        rec(cookies, child, 0, 0);

        return maxnum;
    }
};