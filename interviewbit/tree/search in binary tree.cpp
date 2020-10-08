#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *searchBST(TreeNode *root, int val)
{
    // base
    if (root == NULL)
        return NULL;
    if (root->val == val)
        return root;
    // rec
    if (val < root->val)
        return searchBST(root->left, val);
    if (val > root->val)
        return searchBST(root->right, val);
    TreeNode *lp = searchBST(root->left, val);
    if (lp == NULL)
        return searchBST(root->right, val);
    return lp;
}