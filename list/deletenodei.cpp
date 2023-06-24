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

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *f = head, *del, *prev = new ListNode(-1, head);
        del = prev;
        while (n > 0 && f != NULL)
        {
            f = f->next;
            n--;
        }
        while (f != NULL)
        {
            f = f->next;
            prev = prev->next;
        }

        // remove node
        if (prev == del)
        {
            head = head->next;
            delete prev->next;
        }
        else if (prev->next->next == NULL)
        {
            delete prev->next;
            prev->next = NULL;
        }
        else
        {
            ListNode *cur = prev->next;
            prev->next = cur->next;
            delete cur;
        }
        delete del;
        return head;
    }
};