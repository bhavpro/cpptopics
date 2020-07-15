#include "Graphheader.hpp"

template <class T>
void Graph<T>::addedge(T u, T v, bool bidir)
{
    adjlist[u].push_back(v);
    if (bidir)
    {
        adjlist[v].push_back(u);
    }
}

template <class T>
void Graph<T>::print()
{
    for (auto keyval : adjlist)
    {
        cout << "\n"
             << keyval.first << " --> ";
        for (T u : keyval.second)
        {
            cout << u << " , ";
        }
    }
}

template <class T>
void Graph<T>::bfs()
{
    cout << "\n\nBFS\n\n";
    queue<T> q;
    map<T, bool> visited;

    for (pair<T, list<T>> p : adjlist)
    {
        if (!visited[p.first])
        {
            cout << "\n";
            q.push(p.first);
            visited[p.first] = true;
            while (!q.empty())
            {
                T front = q.front();
                q.pop();
                cout << front << " -> ";
                list<T> ll = adjlist[front];
                for (T ele : ll)
                {
                    if (!visited[ele])
                    {
                        q.push(ele);
                        visited[ele] = true;
                    }
                }
            }
        }
    }
}

template <class T>
void Graph<T>::dfs()
{
    cout << "\n\n\nDFS";
    map<T, bool> visited;
    for (pair<T, list<T>> p : adjlist)
    {
        if (!visited[p.first])
        {
            cout << "\n";
            dfshelper(p.first, visited);
        }
    }
}

template <class T>
void Graph<T>::dfshelper(T src, map<T, bool> &visited)
{
    // base
    if (visited[src])
    {
        return;
    }

    // rec
    cout << src << " -> ";
    visited[src] = true;
    list<T> ll = adjlist[src];
    for (T ele : ll)
    {
        dfshelper(ele, visited);
    }
}

template <class T>
void Graph<T>::ssspbfs(T src)
{
    queue<T> q;
    map<T, int> dist;

    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        T front = q.front();
        q.pop();
        list<T> ll = adjlist[front];
        int dp = dist[front];
        for (T ele : ll)
        {
            if (dist.count(ele) == 0)
            {
                q.push(ele);
                dist[ele] = dp + 1;
            }
        }
    }

    cout << "\n\nSSSP";
    for (pair<T, int> p : dist)
    {
        cout << "\n";
        cout << p.first << " --> " << p.second;
    }
}

template <class T>
void Graph<T>::dfstoposort()
{
    map<T, bool> visited;
    list<T> ordering;

    for (pair<T, list<T>> p : adjlist)
    {
        if (!visited[p.first])
        {
            dfstoposorthelper(p.first, visited, ordering);
        }
    }

    cout << "\n\nDFS\n";
    typename list<T>::iterator ptr, end;
    end = ordering.end();
    for (ptr = ordering.begin(); ptr != end; ptr++)
    {
        cout << *ptr << " --> ";
    }
}

template <class T>
void Graph<T>::dfstoposorthelper(T src, map<T, bool> &visited, list<T> &ordering)
{
    // base
    if (visited[src])
    {
        return;
    }

    // rec
    list<T> ll = adjlist[src];
    visited[src] = true;
    for (T ele : ll)
    {
        if (!visited[ele])
        {
            dfstoposorthelper(ele, visited, ordering);
        }
    }
    ordering.push_front(src);
}

template <class T>
void Graph<T>::bfstoposort()
{
    cout << "\n";
    map<T, int> indegree;
    queue<T> q;

    for (pair<T, list<T>> ele : adjlist) // init indegree with 0
    {
        indegree[ele.first] = 0;
    }

    for (pair<T, list<T>> ele : adjlist) // calc indegree
    {
        for (T el : ele.second)
        {
            indegree[el]++;
        }
    }

    for (pair<T, int> ele : indegree) //pushing element with 0 indegree
    {
        if (ele.second == 0)
        {
            q.push(ele.first);
        }
    }

    while (!q.empty())
    {
        T front = q.front();
        q.pop();
        list<T> ll = adjlist[front];
        for (T ele : ll)
        {
            if (--indegree[ele] == 0)
            {
                q.push(ele);
            }
        }
        cout << front << " --> ";
    }
}