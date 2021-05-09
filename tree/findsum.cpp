#include <iostream>
#include "../../c++ headers/tree/tree.hpp"

using namespace std;
using namespace kbbk;

int findsum(Treenode<int> *root)
{
    // base

    // root
    int sum = root->data;
    for (Treenode<int> *ch : root->children)
        sum += findsum(ch);

    return sum;
}

int main()
{
    freopen("input.txt", "r", stdin);
    Tree<int> t;
    t.inputlw();
    cout << findsum(t.root);
    return 0;
}