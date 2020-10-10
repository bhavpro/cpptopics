#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#define Node ListNode
#define data val

ListNode *partition(ListNode *head, int x)
{
    struct Node *smallerHead = NULL, *smallerLast = NULL;
    struct Node *greaterLast = NULL, *greaterHead = NULL;
    struct Node *equalHead = NULL, *equalLast = NULL;

    while (head != NULL)
    {
        // If current node is equal to x, append it
        // to the list of x values
        if (head->data == x)
        {
            if (equalHead == NULL)
                equalHead = equalLast = head;
            else
            {
                equalLast->next = head;
                equalLast = equalLast->next;
            }
        }

        // If current node is less than X, append
        // it to the list of smaller values
        else if (head->data < x)
        {
            if (smallerHead == NULL)
                smallerLast = smallerHead = head;
            else
            {
                smallerLast->next = head;
                smallerLast = head;
            }
        }
        else // Append to the list of greater values
        {
            if (greaterHead == NULL)
                greaterLast = greaterHead = head;
            else
            {
                greaterLast->next = head;
                greaterLast = head;
            }
        }

        head = head->next;
    }

    // Fix end of greater linked list to NULL if this
    // list has some nodes
    if (greaterLast != NULL)
        greaterLast->next = NULL;

    // Connect three lists

    // If smaller list is empty
    if (smallerHead == NULL)
    {
        if (equalHead == NULL)
            return greaterHead;
        equalLast->next = greaterHead;
        return equalHead;
    }

    // If smaller list is not empty
    // and equal list is empty
    if (equalHead == NULL)
    {
        smallerLast->next = greaterHead;
        return smallerHead;
    }

    // If both smaller and equal list
    // are non-empty
    smallerLast->next = equalHead;
    equalLast->next = greaterHead;
    return smallerHead;
}
