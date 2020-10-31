#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> children(v + 1, 0), parent(v + 1, 0);
    for (int i = 0; i < e; i++)
    {
        int s, d;
        cin >> s >> d;
        int p = min(s, d);
        int c = max(s, d);
        parent[c]++;
        children[p]++;
    }
    int nohv = 0;
    for (int i = 1; i <= v; i++)
        if (parent[i] < children[i] && parent[i] && children[i])
            nohv++;
    return 0;
}