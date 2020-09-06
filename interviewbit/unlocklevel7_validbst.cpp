#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isbst(TreeNode *A, int s, int e)
{
    // base

    // rec
    bool is1 = true, is2 = true, now = false;
    if (A->left != NULL)
    {
        is1 = isbst(A->left, s, A->val);
    }
    if (A->right != NULL)
    {
        is2 = isbst(A->right, A->val, e);
    }
    if (s <= A->val && A->val <= e)
        now = true;

    return (is1 && is2 && now);
}

int isValidBST(TreeNode *A)
{
    if (isbst(A, 1, INT_MAX))
        return 1;
    else
        return 0;
}
