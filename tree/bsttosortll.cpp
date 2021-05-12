#include <iostream>
#include <list>
#include "../../c++ headers/bst/bst.hpp"

using namespace std;
using namespace kbbk;

list<int> bttoll(bst<int> t, int i = 1)
{
    // base
    if (t.bt[i] == -1)
    {
        return list<int>();
    }

    // rec
    list<int> left = bttoll(t, i << 1);
    list<int> right = bttoll(t, (i << 1) + 1);
    left.push_back(t.bt[i]);
    left.splice(left.end(), right);
    return left;
}

int main()
{
    bst<int> t;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;
    t.from_sortedarray(a, n);
    list<int> ll = bttoll(t);
    for (int x : ll)
        cout << x << " ";
    return 0;
}