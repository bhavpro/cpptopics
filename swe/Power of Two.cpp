#include <bits/stdc++.h>

using namespace std;

bool powerOfTwo(int input)
{
    int power = log2(input);
    return (input == (1 << power));
}