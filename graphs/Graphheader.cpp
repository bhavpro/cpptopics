#include <iostream>
#include <map>
#include <list>

using namespace std;

template <class T>
class Graph
{
    map<T, list<T>> adjl;

public:
    Graph()
    {
    }

    void addedge(T u, T v, bool bidir = true)
    {
        adjl[u].push_back(v);
        if (bidir)
        {
            adjl[v].push_back(u);
        }
    }

    void print()
    {
        for (auto keyval : adjl)
        {
            cout << "\n"
                 << keyval.first << " --> ";
            for (T u : keyval.second)
            {
                cout << u << " , ";
            }
        }
    }
};

int main()
{
    Graph<int> g;
    g.addedge(1,4);
    g.addedge(1,3);g.addedge(2,3,false);
    g.print();
    return 0;
}