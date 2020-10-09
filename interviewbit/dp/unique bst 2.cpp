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

TreeNode *getcopy(TreeNode *root)
{
    // base
    if (root == NULL)
        return NULL;

    // rec
    TreeNode *left = getcopy(root->left);
    TreeNode *right = getcopy(root->right);
    TreeNode *nnode = new TreeNode(root->val);
    nnode->left = left;
    nnode->right = right;
    return nnode;
}

vector<TreeNode *> rec(int s, int e)
{
    // base
    if (s == e)
    {
        TreeNode *root = new TreeNode(s);
        return vector<TreeNode *>({root});
    }

    if (s > e)
    {

        return vector<TreeNode *>({NULL});
    }

    // rec
    vector<TreeNode *> ans;
    for (int r = s; r <= e; r++)
    {
        vector<TreeNode *> lp = rec(s, r - 1);
        vector<TreeNode *> rp = rec(r + 1, e);
        for (int i = 0; i < lp.size(); i++)
        {
            for (int j = 0; j < rp.size(); j++)
            {
                TreeNode *left = getcopy(lp[i]);
                TreeNode *right = getcopy(rp[j]);
                TreeNode *root = new TreeNode(r, left, right);
                ans.push_back(root);
            }
        }
    }
    return ans;
}

vector<TreeNode *> generateTrees(int n)
{
    vector<TreeNode *> root = rec(1, n);
    if (root[0] == NULL)
        return vector<TreeNode *>();
    return root;
}
