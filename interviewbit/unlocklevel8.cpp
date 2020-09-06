#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *makecopy(TreeNode *ptr)
{
    // base
    if (ptr == NULL)
        return NULL;

    // rec
    TreeNode *temp = new TreeNode(ptr->val);
    if (ptr->left != NULL)
        temp->left = makecopy(ptr->left);
    if (ptr->right != NULL)
        temp->right = makecopy(ptr->right);
    return temp;
}

vector<TreeNode *> makebst(int root, set<int> &avail)
{
    
}

vector<TreeNode *> generateTrees(int A)
{
    
}
