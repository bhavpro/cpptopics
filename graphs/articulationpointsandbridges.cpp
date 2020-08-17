#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define ll long long
#define pb push_back

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); /*
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE*/
}
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


#define pii pair<int,int>
#define unom unordered_map<int,list<int>>
#define mod 99824453

vector<int> a;
vector<int> bn;
 unom edge;

void calcbn(long long int x)
{
    for(int i = 1; i < 9;i++)
    {
        if(pow(i,2) < x)
        {
            bn.push_back(i);
        }
    }
    int l = bn[bn.size() - 1];
    int n = 5 * pow(10,5);
    for(int i = 10;i <=n;i++)
    {
        int num = i;
        long long sum = 0;
        while(num != 0)
        {
        
            long long s = (num % 10);
            sum = (sum + (s * s) % mod)% mod;
            num /= 10;
        }
        if(sum <= x)
        {
            bn.push_back(i);
        }

        if(i % 10 == l)
        {
            i += (10 - l - 1);
        }
    }
}

int dfssum(int child)
{
    // base

    // rec
    long long sum = bn[a[child]];
    for(int ch : edge[child])
    {
        sum = (sum + dfssum(ch) % mod) %  mod;
    }
    return sum;
}

int sumbn(int i)
{
    list<int> chl = edge[i]; 
    long long sum = 0;
    for(int child : chl)
    {
    long long sum = sum + (dfssum(child) % child) % mod; 
    }
    return sum;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,m;
    long long x;
    cin >> n >> m >> x;
    calcbn(x);
   
    for(int i = 1; i < n ;i++)
    {
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
    }
    a.push_back(0);
    for(int i = 1; i <= n;i++)
    {
        int sx;
        cin >> sx;
        a.push_back(sx);
    }
    for(int i = 0; i < m;i++)
    {
        int qn ;
        cin >> qn;
        if(qn == 1)
        {
            int ind,val;
            cin >> ind >> val;
            a[ind] = val;
            continue;
        }
        // qn = 2
        int ind;
        cin >> ind;
        cout << sumbn(ind) << "\n";
    }
    return 0;
}
const int N = 1000005;
vector<ll> g[N];
int disc[N], low[N], t;
vector<int> ap;
vector<pair<int, int>> bridge;

void discdfs(int nod, int par)
{
    int noofchild = 0;
    // base

    // rec
    t++;
    disc[nod] = t;
    low[nod] = t;
    for (int child : g[nod])
    {
        if (disc[child] == 0) // not visited child
        {
            noofchild++;
            discdfs(child, nod);
            low[nod] = min(low[nod], low[child]);
            if (par != 0 && low[child] >= disc[nod])
            {
                ap.push_back(nod);
            }
            if (low[child] > disc[nod])
            {
                bridge.pb(make_pair(nod, child));
            }
        }
        else if (child != par) // back edge
        {
            low[nod] = min(low[nod], low[child]);
        }
    }

    if (par == 0 && noofchild >= 2)
    {
        ap.push_back(par);
    }
}

void solve()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    t = 0;
    discdfs(1, 0);
    cout << "----\n";
    for (int x : ap)
        cout << x << " ";
    cout << ap.size();
    cout << "\n----";
}

int main()
{
    // init();
    solve();
}