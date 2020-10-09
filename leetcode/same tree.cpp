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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    queue<TreeNode *> q1;
    queue<TreeNode *> q2;

    q1.push(p);
    q2.push(q);

    while (!q1.empty() && !q2.empty())
    {
        TreeNode *f = q1.front();
        TreeNode *s = q2.front();
        q1.pop();
        q2.pop();
        if (f == NULL || s == NULL)
        {
            if (f == NULL && s == NULL)
                continue;
            else
                return false;
        }
        if (f->val != s->val)
            return false;
        if (f != NULL)
        {
            q1.push(f->left);
            q1.push(f->right);
            q2.push(s->left);
            q2.push(s->right);
        }
    }
    return true;
}