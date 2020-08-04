#include <bits/stdc++.h>

using namespace std;

int lcs1(int *a, int n)
{
    unordered_map<int, bool> isthere;
    // store arr elements in isthere
    int min = a[0], max = a[0];
    for (int i = 0; i < n; i++)
    {
        isthere[a[i]] = true;
        min = std::min(min, a[i]);
        max = std::max(max, a[i]);
    }

    // loop through
    int maxcount = 0;
    int count = 0;
    for (int i = min; i <= max; i++)
    {
        if (isthere[i] == true)
        {
            count++;
        }
        else
        {
            maxcount = ::max(maxcount, count);
            count = 0;
        }
    }
    return maxcount;
}

int lcs2(int *a, int n)
{
    unordered_map<int, int> streak;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int ele = a[i];
        // if already present
        if (streak[ele] != 0)
        {
            continue;
        }

        // no left or right
        if (streak[ele - 1] == 0 && streak[ele + 1] == 0)
        {
            streak[ele] = 1;
            max = ::max(max, 1);
            continue;
        }

        // only left
        if (streak[ele - 1] != 0 && streak[ele + 1] == 0)
        {
            int len1 = streak[ele - 1];
            streak[ele] = len1 + 1;
            streak[ele - len1] = streak[ele];
            max = ::max(max, streak[ele]);
            continue;
        }

        // only right
        if (streak[ele + 1] != 0 && streak[ele - 1] == 0)
        {
            int len2 = streak[ele + 1];
            streak[ele] = len2 + 1;
            streak[ele + len2] = streak[ele];
            max = ::max(max, streak[ele]);
            continue;
        }

        int len1 = streak[ele - 1];
        int len2 = streak[ele + 1];
        streak[ele] = len1 + len2 + 1;
        streak[ele + len2] = streak[ele];
        streak[ele - len1] = streak[ele];
        max = ::max(max, streak[ele]);
    }
    return max;
}

int lcs3(int *a, int n)
{
    unordered_map<int, bool> isthere;
    for (int i = 0; i < n; i++)
    {
        isthere[a[i]] = true;
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int ele = a[i];
        if (isthere[ele - 1] == true)
        {
            continue;
        }
        else
        {
            int count = 0;
            int x = ele;
            while (isthere[x] == true)
            {
                x++;
                count++;
            }
            max = ::max(max, count);
        }
    }
    return max;
}

int main()
{
    int a[] = {10, 4, 20, 1, 3, 6, 5,7,19};
    int n = sizeof(a) / sizeof(int);
    cout << lcs3(a, n);
    return 0;
}