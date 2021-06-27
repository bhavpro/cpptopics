#include <iostream>
#include <queue>

using namespace std;

struct edge
{
    int w, s, d;
};
bool operator>(const edge &a, const edge &b)
{
    return a.w > b.w;
}
struct dsu
{
    int cc;
    vector<int> par;
    dsu(int n)
    {
        cc = n;
        par.resize(n);
        for (int i = 0; i < cc; i++)
            par[i] = i;
    }

    int getp(int n)
    {
        if (par[n] == n)
            return n;
        return par[n] = getp(par[n]);
    }

    void unionit(int a, int b)
    {
        int pa = getp(a);
        int pb = getp(b);
        if (pa != pb)
        {
            par[pa] = pb;
            cc--;
        }
    }

    bool samecomp(int a, int b)
    {
        if (getp(a) == getp(b))
            return true;
        return false;
    }
};

vector<edge> kruskal(priority_queue<edge, vector<edge>, greater<edge>> pq, int v, int e)
{
    vector<edge> ans;
    dsu ufa(v);
    int count = 0;
    while (!pq.empty() && count < v)
    {
        edge cur = pq.top();
        pq.pop();
        if (!ufa.samecomp(cur.s, cur.d))
        {
            ufa.unionit(cur.s, cur.d);
            ans.push_back(cur);
        }
    }
    return ans;
}

int main()
{
    int v, e;
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        edge pqe;
        cin >> pqe.s >> pqe.d >> pqe.w;
        pq.push(pqe);
    }
    vector<edge> ans = kruskal(pq, v, e);
    for (edge edg : ans)
        cout << "\n"
             << edg.s << " -- " << edg.d << " : " << edg.w;
    return 0;
}