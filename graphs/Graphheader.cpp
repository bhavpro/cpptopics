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
    
}