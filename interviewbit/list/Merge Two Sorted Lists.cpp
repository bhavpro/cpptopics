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

ListNode *mergeTwoLists(ListNode *A, ListNode *B)
{
    ListNode *h, *t;
    h = new ListNode(0);
    t = h;
    while (A != NULL && B != NULL)
    {
        if (A->val < B->val)
        {
            t->next = A;
            t = t->next;
            A = A->next;
        }
        else
        {
            t->next = B;
            t = t->next;
            B = B->next;
        }
    }

    while (A != NULL)
    {
        t->next = A;
        t = t->next;
        A = A->next;
    }

    while (B != NULL)
    {
        t->next = B;
        t = t->next;
        B = B->next;
    }

    t->next = NULL;
    t = h;
    h = h->next;
    delete t;
    return h;
}