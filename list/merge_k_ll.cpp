#include <vector>
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void push(ListNode *&head, ListNode *&tail, int val)
{
    if (head == NULL)
        head = tail = new ListNode(val);
    else
    {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
}

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *ah = NULL, *at = NULL;
        vector<ListNode *> heada;
        for (ListNode *f : lists)
            if (f != NULL)
                heada.push_back(f);

        while (heada.size() > 0)
        {
            // do work
            int minv = 1e9, minind;
            int ind = -1;
            for (ListNode *ll : heada)
            {
                ind++;
                if (ll->val < minv)
                {
                    minv = ll->val;
                    minind = ind;
                }
            }

            push(ah, at, minv);

            // pop lists if there is NULL nodes
            heada[minind] = heada[minind]->next;
            if (heada[minind] == NULL)
            {
                heada[minind] = heada[heada.size() - 1];
                heada.pop_back();
            }
        }
        return ah;
    }
};