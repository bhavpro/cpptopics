#include <iostream>

using namespace std;

int xorall(int *a, int n)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = temp ^ a[i];
    }
    return temp;
}

int getsetpos(int x)
{
    int n = 0;
    while(x != 0)
    {
        if(x & 1)
        {
            return n;
        }
        x >>= 1;
        n++;
    }
    return -1;
}

bool getatpos(int a, int pos)
{
    a >>= pos;
    return (a & 1);
}

void diverge(int *a, int n, int *b, int &bn, int *c, int &cn, int pos)
{
    bn = 0;
    cn = 0;
    for (int i = 0; i < n; i++)
    {
        if(getatpos(a[i], pos) == 0)
        {
            b[bn++] = a[i];
        }
        else
        {
            c[cn++] = a[i];
        }
    }
}

void unique2(int *a, int n, int &x, int &y)
{
    int xor2 = xorall(a, n);
    int pos = getsetpos(xor2);
    int *b = new int[n];
    int *c = new int[n];
    int bn = 0, cn = 0;
    diverge(a, n, b, bn, c, cn, pos);
    x = xorall(b, bn);
    y = x ^ xor2;

    delete[] b;
    delete[] c;
}

int main()
{
    int n, x, y;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unique2(a, n, x, y);
    cout << x << " " << y;
    delete[] a;
    return 0;
}