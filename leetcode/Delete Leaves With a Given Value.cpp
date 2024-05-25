#include <stack>
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct StackFrame
{
	TreeNode *root, *par;
	bool vl, vr, left;

	StackFrame(TreeNode *root, TreeNode *par, bool vl, bool vr, bool left) : root(root), vl(vl), vr(vr), par(par), left(left)
	{
	}
};

class Solution
{
public:
	TreeNode *removeLeafNodes(TreeNode *root, int target)
	{
		stack<StackFrame> s;
		TreeNode *node = new TreeNode(-1, root, NULL);
		s.push(StackFrame(root, node, false, false, true));
		while (!s.empty())
		{
			StackFrame &sf = s.top();

			if (sf.root == NULL)
			{
				s.pop();
				continue;
			}

			if (!sf.vl)
			{
				s.push(StackFrame(sf.root->left, sf.root, false, false, true));
				sf.vl = true;
			}
			else if (!sf.vr)
			{
				s.push(StackFrame(sf.root->right, sf.root, false, false, false));
				sf.vr = true;
			}
			else
			{
				TreeNode *root = sf.root;
				if (root->left == NULL && root->right == NULL && root->val == target )
				{

					if (sf.left)
						sf.par->left = NULL;
					else
						sf.par->right = NULL;

					delete root;
				}
				s.pop();
			}
		}
		return node->left;
	}
};

int main()
{
	TreeNode *a = new TreeNode(1, new TreeNode(1), new TreeNode(1));
	Solution s;
	a = s.removeLeafNodes(a, 1);

}