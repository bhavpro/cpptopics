#include <bits/stdc++.h>

using namespace std;

int main()
{
    int *a = new int[3];
    cout << a[0] << a[2] << a[1];
    delete[] a;
}