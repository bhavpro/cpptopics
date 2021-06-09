#include <iostream>
#include <climits>
#include "../../c++ headers/tree/tree.hpp"

using namespace std;
using namespace kbbk;

int nl(Treenode<int> *tn, int num)
{
    // base

    // rec
    int maxi = INT_MAX;
    for (Treenode<int> *ch : tn->children)
        maxi = min(maxi, nl(ch, num));

    if (tn->data > num)
        maxi = min(maxi, tn->data);

    return maxi;
}

int main()
{
   freopen("input.txt","r",stdin);
    Tree<int> t;
    int find;
    cin >> find;
    t.inputlw();
    cout << nl(t.root, find);

    return 0;
}