#include <bits/stdc++.h>

using namespace std;

void build(int *a, int s, int e, vector<int> &seg, int i)
{
    // base
    if (s == e)
    {
        seg[i] = a[s];
        return;
    }

    // rec
    int mid = (s + e) >> 1;
    build(a, s, mid, seg, i << 1);
    build(a, mid + 1, e, seg, (i << 1) + 1);
    seg[i] = min(seg[(i << 1)], seg[(i << 1) + 1]);
}

void print(const vector<int> &seg)
{
    for (int i = 1; i < seg.size(); i++)
    {
        cout << seg[i] << " ";
    }
}

int query(vector<int> &seg, int s, int e, int qs, int qe, int i)
{
    // base
    if (s > qe || e < qs)
    {
        return INT_MAX;
    }

    if (s >= qs && e <= qe)
    {
        return seg[i];
    }

    // rec
    return min(query(seg, s, (s + e) >> 1, qs, qe, (i << 1)), query(seg, ((s + e) >> 1) + 1, e, qs, qe, (i << 1) + 1));
}

void updateelement(vector<int> &seg, int s, int e, int elei, int inc, int i)
{
}

void updaterange(vector<int> &seg, int s, int e, int l, int r, int inc, int i)
{
    // base
    if (l > e || r < s)
    {
        return;
    }

    if (s == e)
    {
        seg[i] += 10;
        return;
    }

    // rec
    cout << s << " " << e << "\n"
         << flush;
    int mid = s + e;
    mid >>= 1;
    updaterange(seg, s, mid, l, r, inc, i << 1);
    updaterange(seg, mid + 1, e, l, r, inc, (i << 1) + 1);
    seg[i] = min(seg[i << 1], seg[(i << 1) + 1]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> segtree((n << 2) + 1);
    vector<int> lazy((n << 2) + 1, 0);
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    segtree[0] = n;
    build(a, 0, n - 1, segtree, 1);
    while (true)
    {
        int op;
        system("clear");
        cout << "\n1. print \n2.Query \n3. Update Element \n4. Update Range \n5. Exit\n\n";
        cin >> op;
        system("clear");
        if (op == 5)
        {
            break;
        }
        switch (op)
        {
        case 1:
            print(segtree);
            break;
        case 2:
            int si2, ei2;
            cout << "\nGive Start index : ";
            cin >> si2;
            cout << "\nGive End index :";
            cin >> ei2;
            cout << query(segtree, 0, n - 1, si2, ei2, 1);
            break;
        case 3:
            int ind, inc3;
            cout << "\nGive index : ";
            cin >> ind;
            cout << "\nGive increment : ";
            cin >> inc3;
            updateelement(segtree, 0, n - 1, ind, inc3, 1);
            break;
        case 4:
            int si, ei, inc;
            cout << "\nStart Index : ";
            cin >> si;
            cout << "\nEnd index : ";
            cin >> ei;
            cout << "\nIncrement : ";
            cin >> inc;
            updaterange(segtree, 0, n - 1, si, ei, inc, 1);
            break;
        }
    }
    delete[] a;
    return 0;
}