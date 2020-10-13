#include <iostream>
#include <list>
#include <map>

using namespace std;

template <class T>
class Graph
{
    
};

template <class T>
class Graph1
{
    map<T, list<T>> adjlist;

public:
    Graph1()
    {
    }
    void addedge(T u, T v, bool bidir = true)
    {
        adjlist[u].push_back(v);
        if (bidir == true)
        {
            adjlist[v].push_back(u);
        }
    }

    void print();
};

template <class T>
void Graph1<T>::print()
{
    /*for (pair<T, list<T>> row : adjlist)
        {
            cout << row.first << " -> ";
            for (T node : row.second)
            {
                cout << node << " , ";
            }
            cout << " \n";
        }*/
    using typename map<T, list<T>>::iterator ptr, end;
    end = adjlist.end();
    for (ptr = adjlist.begin(); ptr != end; ptr++)
    {
        cout << ptr->first << " -> ";
        for (T node : ptr->second)
        {
            cout << node << " , ";
        }
        cout << " \n";
    }
}

int main()
{
    Graph1<string> g;
    g.addedge("delhi", "srinagar");
    g.addedge("delhi", "agra");
    g.addedge("delhi", "mumbai");
    g.addedge("srinagar", "mumbai");
    g.print();
    return 0;
}