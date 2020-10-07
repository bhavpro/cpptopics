#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nextLargerNodes(ListNode *head)
{
    vector<int> ans;
    ListNode *ptr = head;
    while (ptr != NULL)
    {
        ListNode *temp = ptr->next;
        while (temp != NULL)
        {
            if (ptr->val < temp->val)
            {
                ans.push_back(temp->val);
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL)
            ans.push_back(0);

        ptr = ptr->next;
    }
    return ans;
}

class Solution
{

    int maxi;
    int ind;

public:
    Solution(vector<int> &w)
    {
        int n = w.size();
        maxi = n == 0 ? 0 : w[0];
        ind = n == 0 ? -1 : 0;
        for (int i = 0; i < n; i++)
        {
            if (maxi < w[i])
            {
                maxi = w[i];
                ind = i;
            }
        }
    }

    int pickIndex()
    {
        return ind;
    }
};
