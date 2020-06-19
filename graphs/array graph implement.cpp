#include <iostream>
#include <list>

using namespace std;

// graph for int nodes

class Graphs
{
    int v;
    list<int> *adjlist;

public:
    Graphs(int v) : v(v)
    {
        adjlist = new list<int>[v];
    }

    ~Graphs()
    {
        delete[] adjlist;
    }

    void addedge(int init, int final, bool bidir = true)
    {
        adjlist[init].push_back(final);
        if (bidir == true)
        {
            adjlist[final].push_back(init);
        }
    }

    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << " -> ";
            list<int>::iterator ptr, end;
            end = adjlist[i].end();
            for (ptr = adjlist[i].begin(); ptr != end; ptr++)
            {
                cout << *ptr << " , ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    Graphs g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(0, 3);
    g.addedge(3, 1);
    g.addedge(2, 3);

    g.print();
    return 0;
}