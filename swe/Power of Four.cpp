#include <bits/stdc++.h>

using namespace std;

bool powerOfFour(int input)
{
    double power = log(input) / log(4);
    if ((1 << (2 * (int)power)) == input)
        return true;
    return false;
}