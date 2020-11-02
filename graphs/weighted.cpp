#include <bits/stdc++.h>

using namespace std;

template <class T>
class Graph
{
    unordered_map<T, list<pair<T, int>>> adjl;

public:
    void addedge(T u, T v, int w)
    {
        adjl[u].push_back({v, w});
        adjl[v].push_back({u, w});
    }

    unordered_map<T, int> dijsktra(T src)
    {
        unordered_map<T, int> dist;
        unordered_map<T, bool> vis;
        for (auto ele : adjl)
        {
            dist[ele.first] = INT_MAX;
        }
        dist[src] = 0;

        set<pair<int, T>> s;
        s.insert({0, src});
        vis[src] = true;
        while (!s.empty())
        {
            pair<int, T> p = *s.begin();
            s.erase(s.begin());
            //   cout << p.second;
            dist[p.second] = p.first;
            for (auto ch : adjl[p.second])
            {
                if (!vis[ch.second])
                {
                    vis[ch.second] = true;
                    s.insert({dist[p.second] + ch.second, ch.first});
                }
                else
                {
                    for (auto ptr = s.begin(); ptr != s.end(); ptr++)
                    {
                        if ((*ptr).second == ch.first)
                        {
                            //----
                            if ((*ptr).first > dist[p.second] + ch.second)
                            {
                                s.erase(ptr);
                                s.insert({dist[p.second] + ch.second, ch.first});
                            }

                            //-----
                            break;
                        }
                    }
                }
            }
        }
        return dist;
    }
};

int main()
{
    Graph<int> g;
    g.addedge(1, 2, 1);
    g.addedge(1, 3, 4);
    g.addedge(2, 3, 1);
    g.addedge(3, 4, 2);
    g.addedge(1, 4, 7);
    unordered_map<int, int> ans = g.dijsktra(1);
    for (auto p : ans)
    {
        cout << p.first << " --> " << p.second << "\n";
    }
    return 0;
}