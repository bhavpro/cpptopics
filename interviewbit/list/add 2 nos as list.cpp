#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *A, ListNode *B)
{
    ListNode *a = A, *b = B;
    int carry = 0;
    ListNode *H = new ListNode(0);
    ListNode *c = H;
    while (a != NULL && b != NULL)
    {
        int val = a->val + b->val + carry;
        carry = val / 10;
        ListNode *temp = new ListNode(val % 10);
        c->next = temp;
        c = c->next;
        a = a->next;
        b = b->next;
    }
    while (a != NULL)
    {
        int val = a->val + carry;
        carry = val / 10;
        ListNode *temp = new ListNode(val % 10);
        c->next = temp;
        c = c->next;
        a = a->next;
    }
    while (b != NULL)
    {
        int val = b->val + carry;
        carry = val / 10;
        ListNode *temp = new ListNode(val % 10);
        c->next = temp;
        c = c->next;
        b = b->next;
    }
    if (carry)
    {
        ListNode *temp = new ListNode(carry);
        c->next = temp;
    }
    c = H;
    H = H->next;
    delete c;
    return H;
}