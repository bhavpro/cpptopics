#include <bits/stdc++.h>

using namespace std;

struct comp
{
    bool operator()(int a, int b)
    {
        if (a < b)
            return true;
        return false;
    }
};

int main()
{
    priority_queue<int, vector<int>, comp> q;
    int n = 8;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            q.push(i * 2);
        else
            q.push(i / 2);
    }
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    return 0;
}