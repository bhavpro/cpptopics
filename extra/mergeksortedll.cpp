#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *head = NULL, *cur;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            if (head == NULL)
            {
                head = new ListNode(l1->val);
                cur = head;
                l1 = l1->next;
                continue;
            }
            ListNode *temp = new ListNode(l1->val);
            cur->next = temp;
            cur = temp;
            l1 = l1->next;
        }
        else
        {
            if (head == NULL)
            {
                head = new ListNode(l1->val);
                cur = head;
                l2 = l2->next;
                continue;
            }
            ListNode *temp = new ListNode(l2->val);
            cur->next = temp;
            cur = temp;
            l2 = l2->next;
        }
    }

    while (l1 != NULL)
    {
        ListNode *temp = new ListNode(l1->val);
        cur->next = temp;
        cur = temp;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        ListNode *temp = new ListNode(l2->val);
        cur->next = temp;
        cur = temp;
        l2 = l2->next;
    }
    return head;
}

ListNode *divideandmerge(vector<ListNode *> &lists, int s, int e)
{
    // base
    if (s == e)
    {
        return lists[s];
    }
    // rec
    int mid = s + e;
    mid /= 2;
    return merge(divideandmerge(lists, s, mid), divideandmerge(lists, mid + 1, e));
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if(lists.size() == 0)
    {
        return NULL;
    }
    return divideandmerge(lists, 0, lists.size() - 1);
}

int main()
{
}