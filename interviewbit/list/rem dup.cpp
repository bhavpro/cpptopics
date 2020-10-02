#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *A)
{
    if (A == NULL)
        return NULL;
    ListNode *slow = A, *fast = A->next;
    while (fast != NULL)
    {
        if (slow->val == fast->val)
        {
            slow->next = fast->next;
            delete fast;
            fast = slow->next;
        }
        else
        {
            slow = slow->next;
            fast = slow->next;
        }
    }
    return A;
}
