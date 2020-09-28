#include <bits/stdc++.h>

using namespace std;

int bs(int len)
{
    int s0 = 1;
    int s1 = 1;

    for (int i = 2; i <= len; i++)
    {
        int ns0 = s1;
        s1 = s0 + s1;
        s0 = ns0;
    }
    return s0 + s1;
}