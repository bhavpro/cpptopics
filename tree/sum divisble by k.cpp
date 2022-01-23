/*Given a tree with n nodes and each node has a value, find number of paths whose sum is divisible by k where k is an integer*/

#include "../../c++ headers/tree/tree.hpp"
#include <iostream>

using namespace std;
using namespace kbbk;

typedef Treenode<int> tn;

int countpath(tn *root, int k, int sum = 0)
{
    int cnt = 0;
    int newsum = sum + root->data;
    // base
    if (!(newsum % k))
        cnt++;

    // rec
    for (tn *ch : root->children)
        cnt += countpath(ch, k, newsum);
    return cnt;
}

int main()
{
    freopen("input1.txt", "r", stdin);
    Tree<int> t;
    int k;
    t.inputlw();
    cin >> k;
    cout << countpath(t.root, k);
    return 0;
}