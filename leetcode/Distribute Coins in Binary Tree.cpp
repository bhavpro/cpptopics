#include <cmath>
#include <utility>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

class Solution
{
    int moves;
    int rec(TreeNode *root)
    {
        // base
        if (root == NULL)
            return 0;

        // rec
        int pl, pr;
        pl = rec(root->left);
        pr = rec(root->right);
        int ec = pl + pr + root->val - 1;
        moves += abs(ec);
        return ec;
    }

public:
    int distributeCoins(TreeNode *root)
    {
        moves = 0;
        rec(root);
        return moves;
    }
};

// #include <cmath> // For abs()

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int distributeCoins(TreeNode* root) {
//         int total_moves = 0;
//         postorderTraversal(root, total_moves);
//         return total_moves;
//     }

// private:
//     int postorderTraversal(TreeNode* node, int& total_moves) {
//         if (!node) return 0;

//         int left_excess = postorderTraversal(node->left, total_moves);
//         int right_excess = postorderTraversal(node->right, total_moves);

//         int node_excess = node->val + left_excess + right_excess - 1;
//         total_moves += abs(node_excess);

//         return node_excess;
//     }
// };

int main()
{
    TreeNode *root = new TreeNode(0, new TreeNode(3), new TreeNode(0));
    Solution s;
    s.distributeCoins(root);

    delete root;
}