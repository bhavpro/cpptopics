#include <bits/stdc++.h>

using namespace std;

void build(int *a, int s, int e, vector<int> &segtree, int i)
{
    // base
    if (s == e)
    {
        segtree[i] = a[s];
        return;
    }

    // end
    int mid = (s + e) / 2;
    build(a, s, mid, segtree, 2 * i);
    build(a, mid + 1, e, segtree, 2 * i + 1);
    segtree[i] = min(segtree[2 * i], segtree[2 * i + 1]);
}

void print(const vector<int> &seg)
{
    int n = seg[0];
    for (int i = 1; i < seg.size(); i++)
    {
        cout << seg[i] << " ";
    }
}

int query(vector<int> &seg, int s, int e, int qs, int qe, int i)
{
    // base
    if (s >= qs && e <= qe) // complete overlap
    {
        return seg[i];
    }
    if (s > qe || qs > e) // no overlap
    {
        return INT_MAX;
    }

    // rec
    int mid = (s + e) / 2;
    int m1 = query(seg, s, mid, qs, qe, 2 * i);
    int m2 = query(seg, mid + 1, e, qs, qe, 2 * i + 1);
    return min(m1, m2);
}

void updateelement(vector<int> &seg, int s, int e, int elei, int inc, int i)
{
    // base
    if (s == e && s == elei)
    {
        seg[i] += inc;
        return;
    }

    if (elei > e || elei < s)
    {
        return;
    }

    // rec
    int mid = s + e;
    mid >>= 1;
    updateelement(seg, s, mid, elei, inc, i << 1);
    updateelement(seg, mid + 1, e, elei, inc, (i << 1) + 1);
    seg[i] = min(seg[i << 1], seg[(i << 1) + 1]);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> segtree(4 * n + 1);
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    segtree[0] = n;
    build(a, 0, n - 1, segtree, 1);
    print(segtree);
    updateelement(segtree, 0, n - 1, 3, 12, 1);
    cout << query(segtree, 0, n - 1, 0, 5, 1);
    delete[] a;
}