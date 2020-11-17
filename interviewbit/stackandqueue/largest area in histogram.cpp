#include <bits/stdc++.h>

using namespace std;

int largestarea(vector<int> &arr, int n)
{
    // next smaller element index in left
    stack<int> s;
    vector<int> nsil(n);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[i] <= arr[s.top()])
            s.pop();
        if (s.empty())
            nsil[i] = -1;
        else
            nsil[i] = s.top();
        s.push(i);
    }

    // next smaller element index in right
    stack<int> s2;
    vector<int> nsir(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[i] <= arr[s.top()])
            s.pop();
        if (s.empty())
            nsir[i] = -1;
        else
            nsir[i] = s.top();
        s.push(i);
    }

    int la = 0;
    // largest area
    for (int i = 0; i < n; i++)
    {
        int h = arr[i];
        int l = 1;
        if (nsil[i] != -1)
            l += (i - nsil[i] - 1);
        else
            l += (i);
        if (nsir[i] != -1)
            l += (nsir[i] - i - 1);
        else
            l += n - 1 - i;
        la = max(la, l * h);
    }
    return la;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;
    cout << largestarea(arr, n);
    return 0;
}