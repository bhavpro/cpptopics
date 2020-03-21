#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <unordered_map>
#include <queue>
#include <string>

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

//###############################################################################

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
    void dfs();
    void dfshelper(T src, unordered_map<T, bool> &visited);
    void dfsdirected();
    void dfsdirectedhelper(T, unordered_map<T, bool> &, list<T> &);
    void bfstopology();
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

template <class T>
void Graph<T>::dfs()
{
    unordered_map<T, bool> visited;
    int comp = 0;
    T src;
    cout << "\n";
    for (pair<T, list<T>> p : adjlist)
    {
        src = p.first;
        if (visited.count(src) == 0)
        {
            comp++;
            dfshelper(src, visited);
            cout << "\n";
        }
    }
    cout << "\ncurrent graph has " << comp << " components";
}

template <class T>
void Graph<T>::dfshelper(T src, unordered_map<T, bool> &visited)
{
    // base
    if (visited.count(src) > 0)
    {
        return;
    }

    // rec
    cout << src << " , ";
    visited[src] = true;
    list<T> ll = adjlist[src];
    for (T temp : ll)
    {
        dfshelper(temp, visited);
    }
}

template <class T>
void Graph<T>::dfsdirected()
{
    unordered_map<T, bool> visited;
    list<T> ordering;
    for (pair<T, list<T>> temp : adjlist)
    {
        if (visited[temp.first] == false)
        {
            dfsdirectedhelper(temp.first, visited, ordering);
        }
    }
    typename list<T>::iterator ptr, end;
    end = ordering.end();
    for (ptr = ordering.begin(); ptr != end; ptr++)
    {
        cout << *ptr << " --> ";
    }
}

template <class T>
void Graph<T>::dfsdirectedhelper(T src, unordered_map<T, bool> &visited, list<T> &ordering)
{
    for (T ele : adjlist[src])
    {
        if (visited[ele] == false)
        {
            dfsdirectedhelper(ele, visited, ordering);
        }
    }
    visited[src] = true;
    ordering.push_front(src);
}

template <class T>
void Graph<T>::bfstopology()
{
    // initialize
    unordered_map<T, bool> visited;
    unordered_map<T, int> indegree;
    for (pair<T, list<T>> element : adjlist)
    {
        visited[element.first] = false;
        indegree[element.first] = 0;
    }

    // set indegree
    for (pair<T, list<T>> element : adjlist)
    {
        for (T ele : element.second)
        {
            indegree[ele]++;
        }
    }

    queue<T> q;
    // pushing elements with indegree 0
    for (pair<T, int> element : indegree)
    {
        if (element.second == 0)
        {
            q.push(element.first);
            visited[element.first] = true;
        }
    }

    while (!q.empty())
    {
        T temp = q.front();
        for (T child : adjlist[temp])
        {
            indegree[child]--;
            if (indegree[child] == 0 && visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
            }
        }
        cout << temp << " --> ";
        q.pop();
    }
}

} // namespace hashmap

using namespace hashmap;

int main()
{
    Graph<string> g(7);
    g.addedge("English", "Programming", false);
    g.addedge("Maths", "Programming", false);
    g.addedge("Programming", "HTML", false);
    g.addedge("Programming", "Python", false);
    g.addedge("Programming", "Java", false);
    g.addedge("Programming", "JS", false);
    g.addedge("Python", "Web Dev", false);
    g.addedge("HTML", "CSS", false);
    g.addedge("CSS", "JS", false);
    g.addedge("JS", "Web Dev", false);
    g.addedge("Java", "Web Dev", false);
    g.print();
    cout << "\n";
    g.bfstopology();
    return 0;
}