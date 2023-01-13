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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL, *temp;
        int c = 0;
        while (l1 != NULL && l2 != NULL)
        {
            int ans = l1->val + l2->val + c;
            c = 0;
            if (ans > 9)
            {
                c = 1;
                ans %= 10;
            }
            if (head == NULL)
            {
                temp = new ListNode(ans);
                head = temp;
            }

            temp->next = new ListNode(ans);
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }
        while (l1 != NULL)
        {
            int ans = l1->val + c;
            c = 0;
            if (ans > 9)
            {
                c = 1;
                ans %= 10;
            }
            temp->next = new ListNode(ans);
            temp = temp->next;
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            int ans = l2->val + c;
            c = 0;
            if (ans > 9)
            {
                c = 1;
                ans %= 10;
            }
            temp->next = new ListNode(ans);
            temp = temp->next;
            l2 = l2->next;
        }
        if (c)
            temp->next = new ListNode(1);
        temp = head->next;
        delete head;
        return temp;
    }
};