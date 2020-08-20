#include <bits/stdc++.h>

using namespace std;

void nullfunc()
{
}

template <class T>
class Graph
{
    unordered_map<T, list<pair<T, int>>> adjl;

public:
    void addedge(const T, const T, int, bool bidir = true);
    void printadjl();
    void dijkstras(T);
};

template <class T>
void Graph<T>::addedge(const T u, const T v, int dist, bool bidir)
{
    adjl[u].push_back({v, dist});
    bidir == true ? adjl[v].push_back({u, dist}) : nullfunc();
}

template <class T>
void Graph<T>::printadjl()
{
    for (auto l : adjl)
    {
        cout << l.first << " --> ";
        for (auto lis : l.second)
        {
            cout << " ( " << lis.first << " , " << lis.second << " ) , ";
        }
        cout << "\n";
    }
}

template <class T>
void Graph<T>::dijkstras(T src)
{
    unordered_map<T, int> dist;
    map<T, bool> visi;
    set<pair<int, T>> s;
    s.insert({0, src});
    visi[src] = true;
    dist[src] = 0;

    while (!s.empty())
    {
        auto a = s.begin();
        T node = (*a).second;
        int noddist = (*a).first;
        dist[node] = noddist;
        s.erase(a);
        for (auto ch : adjl[node])
        {
            int tempd = noddist + ch.second;
            if (!visi[ch.first])
            {
                s.insert({tempd, ch.first});
                visi[ch.first]=true;
            }
            else
            {
                for (auto ptr = s.begin(); ptr != s.end(); ptr++)
                {
                    if (ptr->second == ch.first) // ele still in set
                    {
                        if (tempd < ptr->first)
                        {
                            s.erase(ptr);
                            s.insert({tempd, ch.first});
                        }
                        break;
                    }
                }
            }
        }
    }
    for (auto p : dist)
    {
        cout << p.first << " --> " << p.second << "\n";
    }
}

int main()
{
    /*  Graph<string> g;
    g.addedge("amritsar", "delhi", 1);
    g.addedge("amritsar", "jaipur", 4);
    g.addedge("jaipur", "delhi", 2);
    g.addedge("jaipur", "mumbai", 8);
    g.addedge("bhopal", "agra", 2);
    g.addedge("mumbai", "bhopal", 3);
    g.addedge("agra", "delhi", 1);*/
    Graph<int> g;
    g.addedge(1, 2, 7);
    g.addedge(1, 3, 4);
    g.addedge(1, 4, 1);
    g.addedge(3, 4, 1);
    g.addedge(2, 3, 2);
    g.printadjl();
    g.dijkstras(1);
    return 0;
}