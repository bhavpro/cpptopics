#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

struct interval
{
    int s, e;
};

bool sortit(interval a, interval b)
{
    bool ans = false;
    ans = a.s < b.s;
    if (!(a.s ^ b.s))
        ans = a.e <= b.e;
    return ans;
}

typedef vector<pair<interval, interval>> vpil;

vpil findconf(interval *arr, int n)
{
    vpil ans;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(arr[i].e > arr[j].s)
            {
                ans.push_back(make_pair(arr[i],arr[j]));
                continue;
            }
            else
            {
                break;
            }
        }
    }
    return ans;
}

int main()
{
    interval arr[] = {{4, 5},
                      {2, 3},
                      {3, 6},
                      {5, 7},
                      {7, 8}};

    int n = sizeof(arr) / sizeof(interval);

    sort(arr, arr + n, sortit);
    vpil ans = findconf(arr, n);
    for (pair<interval, interval> x : ans)
        cout << x.first.s << "-" << x.first.e << " : " << x.second.s << "-" << x.second.e << "\n";

    return 0;
}