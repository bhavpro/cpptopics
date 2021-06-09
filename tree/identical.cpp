#include <iostream>
#include "../../c++ headers/tree/tree.hpp"

using namespace std;
using namespace kbbk;

bool isidentical(Treenode<int> *tn1, Treenode<int> *tn2)
{
    unordered_map<int, Treenode<int> *> um1, um2;
    if (tn1->data != tn2->data)
        return false;

    if (tn1->children.size() != tn2->children.size())
        return false;

    for (Treenode<int> *ch : tn1->children)
        um1[ch->data] = ch;

    bool total = true;
    for (Treenode<int> *ch : tn2->children)
    {
        int data2 = ch->data;
        if (um1[data2])
        {
            total = total && isidentical(um1[data2], ch);
            um1[data2] = NULL;
        }
        else
        {
            return false;
        }
    }
    return total;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    Tree<int> t1;
    t1.inputlw();
    Tree<int> t2;
    t2.inputlw();

    cout << isidentical(t1.root, t2.root);
    return 0;
}