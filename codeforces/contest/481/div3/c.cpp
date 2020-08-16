#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> llpair;

vector<ll> sum;

llpair mapit(ll x)
{

    llpair ans;
    vector<ll>::iterator ptr = lower_bound(sum.begin(), sum.end(), x);
    ll d = ptr - sum.begin();
    ans.first = d + 1;
    ans.second = x - (d != 0 ? sum[d - 1] : 0);
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    ll n, m, *a;
    cin >> n >> m;
    a = new ll[n];
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        ::sum.push_back(sum);
    }
    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        llpair ans = mapit(x);
        cout << ans.first << " " << ans.second << "\n";
    }
    delete[] a;
    return 0;
}
