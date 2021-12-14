#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct edge
{
    int val;
    int src, dest;
};

bool operator>(const edge &a, const edge &b)
{
    if (a.val >= b.val)
        return true;
    return false;
}

class dsu
{
public:
    dsu(int n);
    int *par;
    int cc;
    int getp(int cur);
    void unionit(int, int);
    bool samecomp(int, int);
    ~dsu()
    {
        delete[] par;
    }
};

dsu::dsu(int n)
{
    cc = n;
    par = new int[n];
    for (int i = 0; i < n; i++)
        par[i] = i;
}

int dsu::getp(int cur)
{
    if (cur == par[cur])
        return cur;
    return par[cur] = getp(par[cur]);
}

void dsu::unionit(int a, int b)
{
    int A = getp(a);
    int B = getp(b);
    if (A != B)
    {
        cc--;
        par[A] = B;
    }
}

bool dsu::samecomp(int a, int b)
{
    if (getp(a) == getp(b))
        return true;
    return false;
}

vector<edge> kruskal(priority_queue<edge, vector<edge>, greater<edge>> pq, int v, int e)
{
    vector<edge> ans;
    dsu ds(v);
    int count = 0;
    for (int i = 0; count < v - 1 && !pq.empty(); i++)
    {
        edge temp = pq.top();
        pq.pop();
        if (!ds.samecomp(temp.src, temp.dest))
        {
            ds.unionit(temp.src, temp.dest);
            ans.push_back(temp);
            count++;
        }
    }
    return ans;
}

int main()
{
    int e, v;
    cin >> v >> e;
    priority_queue<edge, vector<edge>, greater<edge>> minheap;
    for (int i = 0; i < e; i++)
    {
        edge x;
        cin >> x.src >> x.dest >> x.val;
        minheap.push(x);
    }
    vector<edge> ans = kruskal(minheap, v, e);
    for (edge ed : ans)
        cout << ed.src << " - " << ed.dest << " : " << ed.val << "\n";
    return 0;
}