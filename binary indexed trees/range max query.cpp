#include <bits/stdc++.h>

using namespace std;

class FTMAX
{
    int *a;
    int n;

public:
    FTMAX(int n);
    ~FTMAX();
    void update(int j, int val);
    void build(int *a, int n);
    int query(int j);
};

//*************************************************

FTMAX::FTMAX(int n) : n(n)
{
    a = new int[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        a[i] = INT_MIN;
}

FTMAX::~FTMAX()
{
    delete[] a;
}

void FTMAX::update(int j, int val)
{
    for (int k = j; k <= n; k += (k & -k))
    {
        a[k] = max(a[k], val);
    }
}

void FTMAX::build(int *a, int n)
{
    for (int i = 1; i <= n; i++)
    {
        update(i, a[i]);
    }
}

int FTMAX::query(int j)
{
    int maxim = a[j];
    for (int i = j; i != 0; i -= (i & -i))
    {
        maxim = max(a[i], maxim);
    }
    return maxim;
}

//##################################################

int main()
{
    freopen("input.txt", "r", stdin);
    // input
    int n;
    cin >> n;
    int *a = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // process
    FTMAX ft(n);
    ft.build(a, n);

    // output
    int q;
    cin >> q;
    ft.update(1, 10);
    while (q--)
    {
        int j;
        cin >> j;
        cout << ft.query(j) << "\n";
    }
    cout << ft.query(8) << "\n"
         << ft.query(9);
    // end
    delete[] a;
    return 0;
}