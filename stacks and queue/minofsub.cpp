#include <iostream>
#include <queue>

using namespace std;

void getmin(int arr[], int n, int k)
{
    deque<int> dq;
    queue<int> ans;
    dq.push_back(0);
    for (int i = 1; i < k; i++)
    {
        while (!dq.empty() && arr[dq.back()] > arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push(arr[dq.front()]);
    for (int i = k; i < n; i++)
    {
        int itor = i - k;
        if (itor == dq.front())
        {
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] > arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push(arr[dq.front()]);
    }

    while (!ans.empty())
    {
        cout << ans.front() << " -> ";
        ans.pop();
    }
}

int main()
{
    int arr[] = {3, 2, 1, 4, 5, 2, 3, 1};
    int n = sizeof(arr) / sizeof(int);
    int k = 3;
    getmin(arr, n, k);

    return 0;
}