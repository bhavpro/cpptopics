#include <iostream>
#include <vector>
#include "../../c++ headers/bt/bt.hpp"

using namespace std;
using namespace kbbk;

template <typename T>
btnode<T> *constbt(vector<T> &pre, vector<T> &in, int ps, int pe, int is, int ie)
{
    // base
    if (ps > pe || is > ie)
        return NULL;

    // rec
    int lps, lpe, lis, lie;
    int rps, rpe, ris, rie;
    T head = pre[ps];
    btnode<T> *root = new btnode<T>(head);
    int x = is;
    while (head != in[x])
        x++;

    // construct left
    lis = is;
    lie = x - 1;
    lps = ps + 1;
    lpe = ps + (x - is);
    root->left = constbt<T>(pre, in, lps, lpe, lis, lie);

    // construct right
    ris = x + 1;
    rie = ie;
    rps = lpe + 1;
    rpe = pe;
    root->right = constbt<T>(pre, in, rps, rpe, ris, rie);
    return root;
}

int main()
{
    bt<int> t;
    int a[] = {0, 1, 2, 3, 4};
    int b[] = {2, 1, 0, 3, 4};
    vector<int> pre, in;
    for (int x : a)
        pre.push_back(x);
    for (int x : b)
        in.push_back(x);
    t.root = constbt<int>(pre, in, 0, pre.size() - 1, 0, in.size() - 1);
    t.print(t.root);

    return 0;
}