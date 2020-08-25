#include <bits/stdc++.h>

using namespace std;

class FTSUM
{
    int *a;
    int n;

public:
    FTSUM(int n)
    {
        this->n = n;
        a = new int[n + 1];
    }

    ~FTSUM()
    {
        delete[] a;
    }

    void update(int j, int inc);
    void build(int *a, int n);
    long long query(int j);
    long long range(int l, int r);
};

//*********************************************

void FTSUM::update(int j, int inc)
{
    for (int k = j; k <= n; k += (k & -k))
    {
        a[k] += inc;
    }
}

void FTSUM::build(int *a, int n)
{
    for (int j = 1; j <= n; j++)
    {
        update(j, a[j]);
    }
}

long long FTSUM::query(int j)
{
    long long sum = 0;
    for (int k = j; k != 0; k -= (k & -k))
    {
        sum += a[k];
    }
    return sum;
}

long long FTSUM::range(int l, int r)
{
    return query(r) - query(l - 1);
}

//#############################################

int main()
{
    // input
    int n;
    cin >> n;
    int *a = new int[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // process
    FTSUM ft(n);
    ft.build(a, n);

    // output
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << ft.range(l, r) << "\n";
    }
    // end
    delete[] a;
    return 0;
}