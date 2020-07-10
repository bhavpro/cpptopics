#include <iostream>
#include <list>

using namespace std;

class Graph
{
public:
    list<int> *arr;
    int v;

    Graph(int v)
    {
        this->v = v;
        arr = new list<int>[v];
    }

    void addedge(int u, int v, bool bidir = true)
    {
        arr[u].push_back(v);
        if (bidir == true)
        {
            arr[v].push_back(u);
        }
    }

    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "\n"
                 << i << " --> ";
            for (auto b = arr[i].begin(); b != arr[i].end(); b++)
            {
                cout << *b << " , ";
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addedge(0, 1);
    g.addedge(0, 4);
    g.addedge(1, 2);
    g.addedge(1, 3);
    g.addedge(1, 4);
    g.addedge(2, 3);
    g.addedge(3, 4, false);
    g.print();
    return 0;
}