#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *subtract(ListNode *A)
{
    ListNode *s = A;
    ListNode *e = A;
    int n = 1;
    unordered_map<ListNode *, ListNode *> parent;
    parent[e] = NULL;
    while (e->next != NULL)
    {
        parent[e->next] = e;
        e = e->next;
        n++;
    }

    int mid = n >> 1;
    for (int i = 1; i <= mid; i++)
    {
        s->val = e->val - s->val;
        s = s->next;
        e = parent[e];
    }
    return A;
}
