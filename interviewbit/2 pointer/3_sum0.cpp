#include <bits/stdc++.h>

using namespace std;

#define ll long long

class trip
{
public:
    int f, s, t;

    trip(int a, int b, int c)
    {
        f = a;
        s = b;
        t = c;
        this->sort();
    }

    void sort()
    {
        int mini = min(min(f, s), t);
        int maxi = max(max(f, s), t);
        int mid = f + s + t - mini - maxi;
        f = mini;
        s = mid;
        t = maxi;
    }
};

struct hashfn
{
    int operator()(trip a)
    {
        return a.f & a.s & a.t;
    }
};

vector<vector<int>> threeSum(vector<int> &A)
{
    map<trip, bool> exist;
    int n = A.size();
    vector<vector<int>> ans;

    sort(A.begin(), A.end());
    for (int i = 0; i < n - 2; i++)
    {
        int target = -A[i];
        int j = i + 1;
        int k = n - 1;
        while (j < k && k < n)
        {
            long long sum = A[j] + A[k];
            if (sum == target)
            {
                trip temp(A[i], A[j], A[k]);
                if (!exist[temp])
                {
                    exist[temp] = true;
                    ans.push_back({temp.f, temp.s, temp.t});
                }
                k++;
            }
            else if (sum > target)
                j++;
            else
                k++;
        }
    }
    return ans;
}

int main()
{
}