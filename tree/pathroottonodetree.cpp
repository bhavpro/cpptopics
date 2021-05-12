#include <iostream>
#include <vector>
#include "../../c++ headers/bt/bt.hpp"

using namespace std;
using namespace kbbk;

vector<int> *prton(btnode<int> *root, int find)
{
    // base
    if (root == NULL)
        return NULL;

    // rec
    vector<int> *ptr;
    if (find == root->data)
        ptr = new vector<int>;
    else
    {
        ptr = prton(root->left, find);
        if (ptr == NULL)
            ptr = prton(root->right, find);
        if (ptr == NULL)
            return NULL;
    }

    ptr->push_back(root->data);
    return ptr;
}

int main()
{
  freopen("input.txt", "r", stdin);
    bt<int> t;
    t.input();
    int find = 7;
    vector<int> *root = prton(t.root, find);
    t.print(t.root);
    cout << "\n";
    for (int x : *root)
        cout << x << " ";
    delete root;
    return 0;
}