#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void rev(ListNode *mid)
{
    ListNode *prev = NULL;
    ListNode *cur = mid->next;
    ListNode *next = cur->next;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    mid->next = prev;
}

int lPalin(ListNode *A)
{ /*
    if (A->next == NULL)
        return 1;
    if (A->next->next == NULL)
    {
        if (A->next->val == A->val)
            return 1;
        else
            return 0;
    }*/

    int count = 1;
    ListNode *s = A, *f = A;
    while (f->next != NULL && f->next->next != NULL)
    {
        s = s->next;
        f = f->next->next;
        count += 2;
    }
    if (f->next != NULL)
    {
        f = f->next;
        count++;
    }
    // s is at mid , f at end , count is total
    // now reverse after mid
    rev(s);
    ListNode *f1 = A, *f2 = s->next;
    while (f2 != NULL)
    {
        if (f1->val != f2->val)
            return 0;
        f1 = f1->next;
        f2 = f2->next;
    }
    return 1;
}

int main()
{
    ListNode *b, *c, *d;
    b = new ListNode(9);
    c = new ListNode(9);
    d = new ListNode(9);
    b->val = 1;
    c->val = 2;
    d->val = 1;
    b->next = c;
    c->next = d;
    cout << lPalin(b);
    delete b;
    delete c;
    delete d;
}