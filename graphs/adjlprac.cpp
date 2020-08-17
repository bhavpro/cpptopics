#include <bits/stdc++.h>

using namespace std;

template <class T>
class Graph
{
public:
    unordered_map<T, list<T>> adjl;

    Graph()
    {
    }
    void addedge(T, T, bool bidir = true);
    void sssp(T src);
    bool iscyclicbfsundir();
    void dfstoposort();
    void bfstoposort();
};

template <class T>
void Graph<T>::addedge(T a, T b, bool bidir)
{
    adjl[a].push_back(b);
    if (bidir)
        adjl[b].push_back(a);
}

template <class T>
void Graph<T>::sssp(T src)
{
    queue<T> q;
    unordered_map<T, int> dist;
    q.push(src);
    dist[src] = 0;
    while (!q.empty())
    {
        T f = q.front();
        q.pop();
        for (T ch : adjl[f])
        {
            if (dist[ch] == 0)
            {
                dist[ch] = dist[f] + 1;
                q.push(ch);
            }
        }
    }
    cout << "\n\nSSSP";
    for (pair<T, int> p : dist)
    {
        cout << "\n";
        cout << p.first << " --> " << p.second;
    }
}
template <class T>
bool Graph<T>::iscyclicbfsundir()
{
    queue<T> q;
    unordered_map<T, bool> vis;
    unordered_map<T, T> par;
    for (auto node : adjl)
    {
        if (!vis[node.first])
        {
            par[node.first] = node.first;
            vis[node.first] = true;
            q.push(node.first);
            while (!q.empty())
            {
                T f = q.front();
                q.pop();
                for (T ch : adjl[f])
                {
                    if (!vis[ch])
                    {
                        vis[ch] = true;
                        par[ch] = f;
                        q.push(ch);
                    }
                    else if (par[f] == ch)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

template <class T>
void Graph<T>::dfstoposort()
{
}

int main()
{
    Graph<int> g;
    g.addedge(1, 0);
    g.addedge(1, 2);
    g.addedge(2, 4);
    g.addedge(0, 4);
    g.addedge(2, 3);
    g.addedge(3, 4);
    g.addedge(5, 3);
    g.addedge(6, 7);
    g.addedge(6, 8);
    g.sssp(1);
    cout << g.iscyclicbfsundir();
    return 0;
}