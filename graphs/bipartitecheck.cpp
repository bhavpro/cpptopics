#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
vector<int> g[N];
bitset<N> coloured;
bitset<N> visited;

void insert(int a, int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}

bool bcdfs(int cur, int par, bool col)
{
    // base

    // rec
    coloured[cur] = col;
    visited[cur] = 1;
    for (int child : g[cur])
    {
        if (!visited[child])
        {
            if (bcdfs(child, cur, !col) == false)
            {
                return false;
            }
        }
        else if (child != par) //backedge
        {
            if (coloured[child] != coloured[par])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    insert(1, 2);
    insert(3, 2);
    insert(3, 4);
    insert(1, 4);
    insert(4, 5);
    visited.reset();
    coloured.reset();
    cout << (bcdfs(1, 0, 1) == false ? "Not Bipartite" : "Bipartite");
    return 0;
}