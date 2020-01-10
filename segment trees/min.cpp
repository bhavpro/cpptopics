#include <iostream>
#include <limits.h>

using namespace std;

#define INF INT_MAX

class minarr
{
    int *oarr, *marr;
    int n, mn;
    int minranger(int l, int r, int i);
    int func(int a, int b)
    {
        if (a < b)
            return a;
        return b;
    }

public:
    minarr(int arr[], int n);
    void setmins();
    void set(int arr[], int n);
    int getmin();
    int getmin(int ql, int qr, int l, int r, int i);
};

// private
int minarr ::minranger(int l, int r, int i = 1)
{
    // base
    if (l == r)
    {
        int ans = oarr[l];
        marr[i] = ans;
        return ans;
    }

    // rec
    int avg = l + r;
    avg /= 2;
    int leftbranch = minranger(l, avg, 2 * i);
    int rightbranch = minranger(avg + 1, r, 2 * i + 1);
    int ans = func(leftbranch, rightbranch);
    marr[i] = ans;
    return ans;
}

// public

minarr ::minarr(int arr[], int n) : n(n)
{
    set(arr, n);
}

void minarr::setmins()
{
    minranger(0, n - 1);
}

void minarr ::set(int arr[], int n)
{
    this->n = n;
    oarr = new int[n];
    mn = 4 * n + 1;
    marr = new int[mn];
    for (int i = 0; i < n; i++)
    {
        oarr[i] = arr[i];
    }
    setmins();
}

int minarr ::getmin()
{
    return marr[1];
}

int minarr ::getmin(int ql, int qr, int l = 0, int r = -1, int i = 1)
{
    if (r == -1)
    {
        r = n - 1;
        return getmin(ql, qr, l, r, i);
    }

    if (ql <= l && qr >= r) // complete overlap
    {
        return marr[i];
    }

    if (ql > r || qr < l) // no overlap
    {
        return INF;
    }

    // Partial Overlap
    int avg = l + r;
    avg /= 2;
    int lb = getmin(ql, qr, l, avg, 2 * i);
    int rb = getmin(ql, qr, avg + 1, r, 2 * i + 1);
    return func(lb, rb);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    minarr minim(arr, n);
    cout << minim.getmin(2, 5);
    delete[] arr;
}