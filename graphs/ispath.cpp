#include <bits/stdc++.h>

using namespace std;

template <class T>
class Graph
{
public:
    unordered_map<T, list<pair<T, int>>> adjlist;

    Graph();
    void addedge(T src, T dest, int val, bool bidir = true);
    void print();
    bool ispath(T src, T dest);
    bool dfsispath(T src, T dest, unordered_map<T, T> &vis);
};

template <class T>
Graph<T>::Graph()
{
}

template <class T>
void Graph<T>::addedge(T src, T dest, int val, bool bidir)
{
    adjlist[src].push_back({dest, val});
    if (bidir)
        adjlist[dest].push_back({src, val});
}

template <class T>
void Graph<T>::print()
{
    for (pair<T, list<pair<T, int>>> p : adjlist)
    {
        cout << p.first << " --> ";
        for (pair<T, int> val : p.second)
        {
            cout << " (" << val.first << ", " << val.second << ") , ";
        }
        cout << "\n";
    }
}

template <class T>
bool Graph<T>::dfsispath(T src, T dest, unordered_map<T, T> &vis)
{
    // base
    if (src == dest)
        return true;

    // rec
    vis[src] = 1;
    for (pair<T, int> ele : adjlist[src])
    {
        if (!vis[ele.first])
            if (dfsispath(ele.first, dest, vis))
                return true;
    }
    return false;
}

template <class T>
bool Graph<T>::ispath(T src, T dest)
{
    unordered_map<T, T> vis;
    return dfsispath(src, dest, vis);
}

int main()
{
    Graph<int> g;
    g.addedge(0, 1, 10);
    g.addedge(0, 3, 10);
    g.addedge(2, 3, 10);
    g.addedge(2, 1, 10);
    g.addedge(3, 4, 10);
    g.addedge(5, 4, 10);
    g.addedge(6, 5, 10);
    g.addedge(6, 4, 10);

    g.print();

    cout << g.ispath(4, 6);
}