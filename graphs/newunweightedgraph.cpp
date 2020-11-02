#include <bits/stdc++.h>

using namespace std;

#define triplet pair<int, pair<T, T>>
#define source second.first
#define dest second.second
#define wt first

template <class T>
triplet make_trip(T s, T d, int w)
{
    triplet temp;
    temp.source = s;
    temp.dest = d;
    temp.wt = w;
    return temp;
}

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
    int minspantreelengthprims();
    bool isbipartitedfs();
    bool isbipartitebfs();
    void toposort();
    void toposortdfs(unordered_map<T, bool> &, T);
    void toposortbfs();
    bool iscyclicudbfs();
    bool iscyclicddfs();
    bool iscyclicddfshelper(unordered_map<T, bool> &, int);
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

template <class T>
int graph<T>::minspantreelengthprims()
{
    int dist = 0;
    unordered_map<T, bool> vis;
    for (pair<T, list<pair<T, int>>> s : adj)
    {
        if (!vis[s.first])
        {
            priority_queue<triplet, vector<triplet>, greater<triplet>> minheap;
            minheap.push(make_trip(s.first, s.first, 0));
            while (!minheap.empty())
            {
                triplet f = minheap.top();
                minheap.pop();
                T par = f.dest;
                if (!vis[par])
                {
                    vis[par] = true;
                    dist += f.wt;
                    for (pair<T, int> ch : adj[par])
                        if (!vis[ch.first])
                            minheap.push(make_trip(par, ch.first, ch.second));
                }
            }
        }
    }
    return dist;
}

template <class T>
bool graph<T>::isbipartitedfs()
{
    unordered_map<T, int> vis;
    stack<T> s;
    for (pair<T, list<pair<T, int>>> p : adj)
    {
        if (!vis[p.first])
        {
            s.push(p.first);
            vis[p.first] = 1;
            // dfs
            while (!s.empty())
            {
                T par = s.top();
                s.pop();
                for (pair<T, int> ele : adj[par])
                {
                    T ch = ele.first;
                    if (!vis[ch])
                    {
                        vis[ch] = (vis[par] % 2) + 1;
                        s.push(ch);
                    }
                    else if (vis[ch] != ((vis[par] % 2) + 1))
                    {
                        return false;
                    }
                }
            }

            // dfs end
        }
    }
    return true;
}

template <class T>
bool graph<T>::isbipartitebfs()
{
    unordered_map<T, int> col;
    queue<T> q;

    for (pair<T, list<pair<T, int>>> p : adj)
        if (!col[p.first])
        {
            col[p.first] = 1;
            q.push(p.first);
            while (!q.empty())
            {
                T par = q.front();
                q.pop();
                for (pair<T, int> ele : adj[par])
                {
                    T ch = ele.first;
                    if (!col[ch])
                    {
                        col[ch] = (col[par] % 2) + 1;
                        q.push(ch);
                    }
                    else
                    {
                        if ((col[par] % 2 + 1) != col[ch])
                            return false;
                    }
                }
            }
        }
    return true;
}

template <class T>
void graph<T>::toposortdfs(unordered_map<T, bool> &vis, T ele)
{
    vis[ele] = true;
    for (pair<T, int> ch : adj[ele])
        if (!vis[ch.first])
            toposortdfs(vis, ch.first);
    cout << ele << "-->";
}

template <class T>
void graph<T>::toposort()
{
    unordered_map<T, bool> vis;
    for (pair<T, list<pair<T, int>>> ele : adj)
    {
        if (!vis[ele.first])
            toposortdfs(vis, ele.first);
    }
}

template <class T>
void graph<T>::toposortbfs()
{
    unordered_map<T, int> indegree;
    for (auto ele : adj)
    {
        if (!indegree[ele.first])
            indegree[ele.first] = 0;
        for (pair<T, int> ch : adj[ele.first])
            indegree[ch.first]++;
    }
    queue<T> q;
    for (pair<T, int> p : indegree)
        if (p.second == 0)
            q.push(p.first);
    while (!q.empty())
    {
        T cur = q.front();
        cout << cur << "-->";
        q.pop();
        for (pair<T, int> p : adj[cur])
        {
            T ch = p.first;
            indegree[ch]--;
            if (!indegree[ch])
                q.push(ch);
        }
    }
}

template <class T>
bool graph<T>::iscyclicudbfs()
{
}

template <class T>
bool graph<T>::iscyclicddfs()
{
    unordered_map<T, bool> vis;
    for (auto ele : adj)
        if (!vis[ele.first] && iscyclicddfshelper(vis, ele.first))
            return true;
    return false;
}

template <class T>
bool graph<T>::iscyclicddfshelper(unordered_map<T, bool> &vis, int cur)
{
    static unordered_map<T, bool> being;
    if (being[cur])
        return true;

    being[cur] = true;
    vis[cur] = true;
    for (pair<T, int> ch : adj[cur])
    {
        if (!vis[ch.first] && iscyclicddfshelper(vis, ch.first))
            return true;
        else if (being[ch.first])
            return true;
    }
    being[cur] = false;
    return false;
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
        g.addedge(a, b, 0, false);
    }
    cout << g.iscyclicddfs();
    return 0;
}