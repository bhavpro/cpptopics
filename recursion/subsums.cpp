#include <bits/stdc++.h>

using namespace std;

vector<int> subsum(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    for (int i = 0; i < (1 << n); i++)
    {
        int j = 0;
        int temp = i;
        int sum = 0;
        while (temp > 0)
        {
            if (temp & 1)
                sum += arr[j];
            temp >>= 1;
            j++;
        }
        ans.push_back(sum);
    }
    return ans;
}

int subsums(vector<int> &arr, int n, int l, int r)
{
    // divide into 2 arrays
    vector<int> s1, s2, v1, v2;
    int n1 = n >> 1, n2 = n - n1;
    v1.reserve(n1);
    v2.reserve(n2);
    for (int i = 0; i < n; i++)
    {
        if (i < n1)
            v1.push_back(arr[i]);
        else
            v2.push_back(arr[i]);
    }

    // 2 subsums vectors
    s1 = subsum(v1);
    s2 = subsum(v2);

    // binary search
    sort(s2.begin(), s2.end());
    int ans = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        int s = s1[i];
        int nl = l - s;
        int nr = r - s;
        ans += upper_bound(s2.begin(), s2.end(), nr) - lower_bound(s2.begin(), s2.end(), nl);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int l = 3;
    int r = 4;
    cout << subsums(arr, n, l, r);
    return 0;
}