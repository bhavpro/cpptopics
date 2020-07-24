#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
vector<int> g[N];

void insert(int a, int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}

int bfsmin(int cur)
{
    vector<int> count(N, -1);
    queue<pair<int, int>> q;
    q.push({cur, 0});
    count[cur] = 0;
    int mini = INT_MAX;
    while (!q.empty())
    {
        pair<int, int> f = q.front();
        q.pop();
        for (int child : g[f.first])
        {
            if (count[child] == -1) // if not visited
            {
                count[child] = count[f.first] + 1;
                q.push({child, f.first});
                continue;
            }
            else if (child != f.second) // visited but not parent
            {
                mini = min(mini, count[f.first] + count[child] + 1);
            }
        }
    }
    return mini;
}

int main()
{
    insert(1, 2);
    insert(2, 3);
    insert(3, 4);
    insert(4, 1);
    insert(2, 5);
    insert(3, 5);
    int mini;
    for (int i = 1; i <= 5; i++)
    {
        mini = min(mini, bfsmin(i));
    }
    cout << mini;
    return 0;
}