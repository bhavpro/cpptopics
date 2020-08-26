#include <bits/stdc++.h>

using namespace std;

int countdig(int n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

int countnbitno(int num, int n)
{
    int count = 0;
    bitset<11> b;
    b.reset();
    for (int i = 0; i < n; i++)
    {
        b[i] = (num % 10 == 4 ? 0 : 1);
        if (i == 0)
            continue;
        count += (1 << i);
    }
    return b.to_ulong() + 1 + count;
}

int main()
{
    int n;
    cin >> n;
    int nod = countdig(n);
    int count = countnbitno(n, nod);
    cout << count;
    return 0;
}