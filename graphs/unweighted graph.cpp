#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

namespace vectormethod
{
template <class T>
class Graph
{
public:
    int v, size;
    pair<T, list<T>> *adjlist;

    Graph(int v);

    ~Graph()
    {
        delete[] adjlist;
    }

    void addedge(T init, T final, bool bidir = true);
    void print();
};

template <class T>
Graph<T>::Graph(int v) : v(v)
{
    adjlist = new pair<T, list<T>>[v];
    size = 0;
}

template <class T>
void Graph<T>::addedge(T init, T final, bool bidir)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (adjlist[i].first == init)
            break;
    }

    adjlist[i].first = init;
    adjlist[i].second.push_back(final);
    adjlist[i].second.unique();
    size += i == size ? 1 : 0;
    if (bidir == true)
    {
        for (i = 0; i < size; i++)
        {
            if (adjlist[i].first == final)
                break;
        }
        adjlist[i].first = final;
        adjlist[i].second.push_back(init);
        adjlist[i].second.unique();
        size += i == size ? 1 : 0;
    }
}

template <class T>
void Graph<T>::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << adjlist[i].first << " --> ";
        typedef typename list<T>::iterator IT;
        IT ptr;
        IT end;
        end = adjlist[i].second.end();
        for (ptr = adjlist[i].second.begin(); ptr != end; ptr++)
        {
            cout << *ptr << " , ";
        }
        cout << "\n";
    }
}

} // namespace vectormethod

namespace hashmap
{
template <class T>
class Graph
{
public:
    int v;
    unordered_map<T, list<T>> adjlist;
    Graph(int v) : v(v)
    {
    }

    ~Graph()
    {
    }

    void addedge(T init, T final, bool bidir = true)
    {
        adjlist[init].push_back(final);
        if (bidir == true)
        {
            adjlist[final].push_back(init);
        }
    }

    void print();
};

template <class T>
void Graph<T>::print()
{
    for (pair<T, list<T>> element : adjlist)
    {
        cout << element.first << " --> ";
        for (T ele : element.second)
        {
            cout << ele << " , ";
        }
        cout << "\n";
    }
}

} // namespace hashmap

using namespace hashmap;

int main()
{
    Graph<int> g(4);
    g.addedge(1, 4);
    g.addedge(2, 3);
    g.addedge(1, 2);
    g.addedge(1, 3);
    g.print();
    return 0;
}