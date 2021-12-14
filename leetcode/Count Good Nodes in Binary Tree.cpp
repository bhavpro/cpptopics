

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//*************

#include <algorithm>
using namespace std;

class Solution
{
public:
    int goodNodes(TreeNode *root,int curmax = -(1e5))
    {
        // base
        if(root == NULL)
            return 0;

        // rec
        return goodNodes(root->left,max(curmax,root->val)) + goodNodes(root->right,max(curmax,root->val)) + (root->val >= curmax ? 1 : 0); 
    }
};