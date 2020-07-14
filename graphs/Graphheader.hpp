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

    void addedge(T u, T v, bool bidir = true);
    void print();
    void bfs();
    void dfs();

};
