#include <iostream>
#include <utility>
#include "../../c++ headers/tree/tree.hpp"

using namespace std;
using namespace kbbk;

pair<Treenode<int> *, int> nwms(Treenode<int> *root)
{
    int sum = root->data;
    for (Treenode<int> *ch : root->children)
        sum += ch->data;

    pair<Treenode<int> *, int> ans = {root, sum};
    for (Treenode<int> *ch : root->children)
    {
        pair<Treenode<int> *, int> p = nwms(ch);
        if (p.second > ans.second)
            ans = p;
    }
    return ans;
}

int main()
{
    freopen("input.txt","r",stdin);
    Tree<int> t;
    t.inputlw();
    pair<Treenode<int> *, int> p = nwms(t.root);
    cout << "\nSum : " << p.second;
    cout << "\nroot : " << p.first->data;
    return 0;
}