#ifndef BT_CPP
#define BT_CPP

#include "bt.hpp"

bt::bt() { t.resize(1); }

void bt::incsize(int s)
{
    if (t.size() < s + 1)
    {
        t.resize((s + 1) << 1);
    }
}

void bt::rec(int *arr, int *arrend, int i)
{
    if (arr == arrend)
    {
        return;
    }

    // fill val
    incsize(i);
    t[i] == arr[0];

    // fill left
    rec(arr + 1, arrend, i << 1);

    // fill right
}

void bt::build(int *arr, int n)
{
    rec(arr, arr + n, 1);

#endif