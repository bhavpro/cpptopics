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

ListNode *swapPairs(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *temp = head;
    ListNode *prev = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (prev == temp)
        {
            temp = temp->next;
            prev->next = temp->next;
            temp->next = prev;
            head = temp;
            temp = prev->next;
        }
        else
        {
            prev->next = temp->next;
            temp->next = prev->next->next;
            prev->next->next = temp;
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}
