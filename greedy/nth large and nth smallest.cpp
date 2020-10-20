#include <bits/stdc++.h>

using namespace std;

int nthsmallest(int *a, int n, int x)
{
    priority_queue<int> maxheap;
    for (int i = 0; i < n; i++)
    {
        maxheap.push(a[i]);
        while (maxheap.size() > x)
        {
            maxheap.pop();
        }
    }
    return maxheap.top();
}

int nthlargest(int *a, int n, int x)
{
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i = 0; i < n; i++)
    {
        minheap.push(a[i]);
        while (minheap.size() > x)
        {
            minheap.pop();
        }
    }
    return minheap.top();
}

int main()
{
    int a[] = {1, 13, 6, 9, 45, 34, 64, 37, 26, 10};
    int n = sizeof(a) / sizeof(int);
    cout << nthsmallest(a, n, 3) << "\n";
    cout << nthsmallest(a, n, 5) << "\n";
    cout << nthlargest(a, n, 3) << "\n";
    cout << nthlargest(a, n, 5);
}