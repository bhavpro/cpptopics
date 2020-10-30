#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> triplet;
#define wt first
#define src second.first
#define dest second.second

struct dsu
{
    int cc;
    vector<int> par;
    vector<int> rank;
    dsu(int n)
    {
        cc = n;
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int getp(int a)
    {
        if (par[a] == a)
            return a;
        return par[a] = getp(par[a]);
    }

    bool unionit(int a, int b)
    {
        int A = getp(a);
        int B = getp(b);
        if (A != B)
        {
            if (rank[A] > rank[B])
                par[B] = A;
            else if (rank[B] > rank[A])
                par[A] = B;
            else
            {
                par[B] = A;
                rank[A]++;
            }
            cc--;
            return true;
        }
        return false;
    }
};

int main()
{
    freopen("kruskalinput.txt", "r", stdin);
    int v, e;
    cin >> v >> e;
    priority_queue<triplet, vector<triplet>, greater<triplet>> s;
    for (int i = 0; i < e; i++)
    {
        triplet temp;
        cin >> temp.src >> temp.dest >> temp.wt;
        s.push(temp);
    }

    // kruskal
    dsu g(v);
    int sum = 0;
    vector<triplet> ans;
    while (!s.empty())
    {
        triplet t = s.top();
        s.pop();
        if (g.unionit(t.src, t.dest))
        {
            sum += t.wt;
            ans.push_back(t);
        }
    }
    //

    cout << sum << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].src << " -> " << ans[i].dest << " : " << ans[i].wt << "\n";

    return 0;
}