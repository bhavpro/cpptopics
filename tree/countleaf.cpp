#include <iostream>
#include "../../c++ headers/tree/tree.hpp"

using namespace std;
using namespace kbbk;

template <typename T>
int countleaf(Treenode<T> *root)
{
    // base
    if (root == NULL)
        return 0;

    if (root->children.size() == 0)
        return 1;

    // rec
    int sum = {0};

    for (Treenode<T> *ch : root->children)
    {
        sum += countleaf(ch);
    }
    return sum;
}

int main()
{
    freopen("input.txt", "r", stdin);
    Tree<int> t;
    t.inputlw();
    cout << "\n"
         << countleaf<int>(t.root);
    return 0;
}