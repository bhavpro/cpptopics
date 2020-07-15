#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <utility>

using namespace std;

template <class T>
class Graph
{
    map<T, list<T>> adjlist;

public:
    Graph()
    {
    }

    void addedge(T, T, bool bidir = true);
    void print();
    void bfs();
    void dfs();
    void dfshelper(T, map<T, bool> &);
    void ssspbfs(T src);
    void dfstoposort();
    void dfstoposorthelper(T, map<T, bool> &, list<T> &);
    void bfstoposort();
};
