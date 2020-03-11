#include <iostream>
#include <list>
#include <vector>
#include <utility>

using namespace std;

namespace vectormethod
{
template <class T>
class Graph
{
public:
    int v, size;
    bool bidir;
    pair<T, list<T>> *adjlist;

    Graph(int v, bool bidir = true);

    ~Graph()
    {
        delete[] adjlist;
    }

    void addedge(T init, T final);
    void print();
};

template <class T>
Graph<T>::Graph(int v, bool bidir) : v(v), bidir(bidir)
{
    adjlist = new pair<T, list<T>>[v];
    size = 0;
}

template <class T>
void Graph<T>::addedge(T init, T final)
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

using namespace vectormethod;

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