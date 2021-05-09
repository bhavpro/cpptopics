#include <iostream>
#include <vector>
#include "../../c++ headers/bt/bt.hpp"

using namespace std;
using namespace kbbk;

template <typename T>
btnode<T> *constbt(vector<T> &post, vector<T> &in, int ps, int pe, int is, int ie)
{
    // base
    if (ps > pe || is > ie)
        return NULL;

    // rec
    int lps, lpe, lis, lie;
    int rps, rpe, ris, rie;
    T head = post[pe];
    btnode<T> *root = new btnode<T>(head);
    int x = ie;
    while (head != in[x])
        x--;

    // construct left
    lis = is;
    lie = x - 1;
    lps = ps;
    lpe = pe - (ie - x) - 1;
    root->left = constbt<T>(post, in, lps, lpe, lis, lie);

    // construct right
    ris = x + 1;
    rie = ie;
    rps = lpe + 1;
    rpe = pe - 1;
    root->right = constbt<T>(post, in, rps, rpe, ris, rie);
    return root;
}

int main()
{
    bt<int> t;
    int a[] = {2, 1, 4, 3, 0};
    int b[] = {2, 1, 0, 3, 4};
    vector<int> post, in;
    for (int x : a)
        post.push_back(x);
    for (int x : b)
        in.push_back(x);
    t.root = constbt<int>(post, in, 0, post.size() - 1, 0, in.size() - 1);
    t.print(t.root);

    return 0;
}