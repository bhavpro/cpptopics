#include <iostream>
#include <limits.h>
#include <list>
#include <utility>

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
    void update(int index, int val, int l, int r, int i);
    void showtree();
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
    int i;
    for (i = 0; i < n; i++)
    {
        oarr[i] = arr[i];
    }
    mn = 2 * (n + 1);
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

void minarr ::update(int index, int val, int l = 0, int r = -1, int i = 1)
{
    if (r == -1)
    {
        oarr[index] += val;
        r = n - 1;
        update(index, val, l, r, i);
        return;
    }

    // base
    if (l == r && l == index)
    {
        marr[i] += val;
        return;
    }

    // rec
    int avg = l + r;
    avg /= 2;
    if (index <= avg)
    {
        update(index, val, l, avg, 2 * i);
    }
    else
    {
        update(index, val, avg + 1, r, 2 * i + 1);
    }
    marr[i] = func(marr[2 * i], marr[2 * i + 1]);
    return;
}

void minarr ::showtree()
{
    for (int i = 1; i < mn; i++)
    {
        cout << marr[i] << " ";
    }
}

int main()
{
    int n;
    n = 6;
    int *arr = new int[n];
    arr[0] = 1;
    arr[1] = 5;
    arr[2] = 8;
    arr[3] = 7;
    arr[4] = 9;
    arr[5] = 4;
    minarr minim(arr, n);
    minim.showtree();
    minim.update(4, -12);
    cout << "\n";
    minim.showtree();
    cout << "\n";
    cout << minim.getmin(2, 5);
    delete[] arr;
}