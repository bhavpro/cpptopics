#include <iostream>
#include <climits>
#include "../../c++ headers/bt/bt.hpp"

using namespace std;
using namespace kbbk;

bool isbst(btnode<int> *tree, int l, int r)
{
    // base
    if (tree == NULL)
        return true;

    // rec
    int data = tree->data;
    if (data < l || data > r)
        return false;
    if (!isbst(tree->left, l, data) || !isbst(tree->right, data, r))
        return false;
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    bt<int> t;
    t.input();
    cout << isbst(t.root, INT_MIN, INT_MAX);
    return 0;
}