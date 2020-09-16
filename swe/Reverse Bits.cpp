#include <bits/stdc++.h>

using namespace std;

int reverseBits(int input)
{
    int ans = 0;
    while (input != 0)
    {
        ans <<= 1;
        ans += (input & 1);
        input >>= 1;
    }
    return ans;
}