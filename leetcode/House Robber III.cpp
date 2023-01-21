

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    pair<int, int> get(TreeNode *root)
    {
        if (root == NULL)
            return {0, 0};
        pair<int, int> pl = get(root->left);
        pair<int, int> pr = get(root->right);
        pair<int, int> p;
        p.first = root->val + pl.second + pr.second;
        p.second = max(pl.first, pl.second) + max(pr.first, pr.second);
        return p;
    }

    int rob(TreeNode *root)
    {
        pair<int, int> p = get(root);
        return p.first > p.second ? p.first : p.second;
    }
};