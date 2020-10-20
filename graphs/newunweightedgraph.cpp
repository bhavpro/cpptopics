#include <bits/stdc++.h>

using namespace std;

template <class T>
class graph
{
public:
    unordered_map<T, list<pair<T, int>>> adj;
    int v;
    graph();
    void addedge(T, T, int w = 0, bool bidir = true);
    vector<vector<T>> ccomp();
    int dijkstra(T s, T d);
};

//******************

template <class T>
graph<T>::graph()
{
}

template <class T>
void graph<T>::addedge(T a, T b, int w, bool bidir)
{
    adj[a].push_back({b, w});
    if (bidir)
        adj[b].push_back({a, w});
}

template <class T>
vector<vector<T>> graph<T>::ccomp()
{
    vector<vector<T>> ans;
    unordered_map<T, bool> vis;
    for (pair<T, list<pair<T, int>>> ele : adj)
    {
        if (!vis[ele.first])
        {
            vis[ele.first] = true;
            vector<T> pans;
            pans.push_back(ele.first);
            queue<T> q;
            q.push(ele.first);
            while (!q.empty())
            {
                T f = q.front();
                q.pop();
                for (pair<T, int> ch : adj[f])
                {
                    if (!vis[ch.first])
                    {
                        vis[ch.first] = true;
                        q.push(ch.first);
                        pans.push_back(ch.first);
                    }
                }
            }
            ans.push_back(pans);
        }
    }
    return ans;
}

template <class T>
int graph<T>::dijkstra(T s, T d)
{
    unordered_map<T, int> dist;
    for (auto p : adj)
    {
        dist[p.first] = INT_MAX;
    }
    priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> pq;
    unordered_map<T, bool> vis;
    pq.push({0, s});
    while (!pq.empty())
    {
        pair<int, T> f = pq.top();
        pq.pop();
        vis[f.second] = true;
        dist[f.second] = min(dist[f.second], f.first);
        for (pair<T, int> n : adj[f.second])
        {
            if (!vis[n.first])
            {
                pq.push({n.second + dist[f.second], n.first});
            }
        }
    }
    return dist[d];
}

//######################

int main()
{
    freopen("input.txt", "r", stdin);
    graph<int> g;
    int v, e;
    cin >> v >> e;
    g.v = v;
    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g.addedge(a, b, w);
    }
    cout << g.dijkstra(3, 6);
    return 0;
}
