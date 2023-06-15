#include <iostream>
#include <queue>
#include <vector>
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
};

class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int level = -1, maxval = -1e9, sum = -1e9, maxind = 0;
        queue<pair<int, TreeNode *>> q; // level, val
        q.push({1, root});
        while (!q.empty())
        {
            pair<int, TreeNode *> f = q.front();
            q.pop();
            if (f.second->left != NULL)
                q.push({f.first + 1, f.second->left});
            if (f.second->right != NULL)
                q.push({f.first + 1, f.second->right});

            if (level < f.first)
            {
                if (sum > maxval)
                {
                    maxval = sum;
                    maxind = level;
                }
                level = f.first;
                sum = f.second->val;
            }
            else
            {
                sum += f.second->val;
            }
        }
        return sum > maxval ? level : maxind;
    }
};