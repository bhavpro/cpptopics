#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <unordered_map>
#include <queue>

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
    void bfs(T src);
    void sssp(T src);
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

template <class T>
void Graph<T>::bfs(T src)
{
    queue<T> q;
    unordered_map<T, bool> visited;

    q.push(src);
    visited[src] = true;

    T temp;
    list<T> ll;

    while (q.empty() == false)
    {
        temp = q.front();
        q.pop();
        ll = adjlist[temp];
        for (T element : ll)
        {
            if (visited.count(element) == 0)
            {
                q.push(element);
                visited[element] = true;
            }
        }
        cout << temp << " , ";
    }
}

template <class T>
void Graph<T>::sssp(T src)
{
    queue<T> q;
    unordered_map<T, int> dist;

    q.push(src);
    dist[src] = 0;

    list<T> ll;
    T f;

    while (q.empty() == false)
    {
        f = q.front();
        ll = adjlist[f];
        for (T temp : ll)
        {
            if (dist.count(temp) == 0)
            {
                q.push(temp);
                dist[temp] = dist[f] + 1;
            }
        }
        q.pop();
    }

    cout << '\n';

    for (pair<T, int> temp1 : dist)
    {
        cout << temp1.first << " --> " << temp1.second << "\n";
    }
}

} // namespace hashmap

using namespace hashmap;

int main()
{
    Graph<int> g(7);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(1, 3);
    g.addedge(4, 3);
    g.addedge(4, 7);
    g.addedge(7, 6);
    g.addedge(6, 5);
    g.addedge(3, 5);
    g.addedge(2, 6);
    g.print();
    g.bfs(6);
    g.sssp(1);
    return 0;
}