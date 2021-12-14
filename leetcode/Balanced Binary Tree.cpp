
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//****************

#include <utility>
#include <algorithm>
using namespace std;

pair<int, bool> hb(TreeNode *root)
{
    // base
    if (root == NULL)
        return make_pair<int, bool>(0, true);

    // rec

    pair<int, bool> l, r;
    l = hb(root->left);
    r = hb(root->right);
    bool isbal = l.second && r.second && (abs(l.first - r.first) <= 1);
    return make_pair(max(l.first, r.first) + 1, isbal);
}

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return hb(root).first;
    }
};