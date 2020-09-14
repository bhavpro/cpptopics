#include <bits/stdc++.h>

using namespace std;

int solve(int A)
{
    int count = 0;
    while (A != 0)
    {
        if (A & 1)
            break;
        count++;
        A >>= 1;
    }
    return count;
}