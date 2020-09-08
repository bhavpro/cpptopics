#include <bits/stdc++.h>

using namespace std;

unsigned int reverse(unsigned int A)
{
    unsigned int num = 0;
    for (int i = 0; i < 32; i++)
    {
        num <<= 1;
        num += (A & 1);
        A >>= 1;
    }
    return num;
}