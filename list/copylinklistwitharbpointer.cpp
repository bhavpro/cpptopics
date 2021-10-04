#include <iostream>
#include <unordered_map>

using namespace std;

struct node
{
    int val;
    node *next;
    node *arbptr;
};

node *deep_copy_arbitrary_pointer(node *head)
{
    // create a LL copy without arb ptr
    node *temp = head;
    node *ansh = NULL;
    node *ansb = NULL;
    // node *newhead = NULL;
    unordered_map<node *, node *> link;
    while (temp != NULL)
    {
        node *ansn = new node;
        ansn->val = temp->val;
        ansn->next = NULL;
        ansn->arbptr = NULL;
        link[temp] = ansn;
        if (ansh == NULL)
        {
            ansh = ansn;
            ansb = ansn;
            continue;
        }
        ansb->next = ansn;
        ansb = ansn;
        temp = temp->next;
    }

    // mark arb ptr in copy
    temp = head;
    node *tempn = ansh;

    while (tempn != NULL)
    {
        tempn->arbptr = link[temp->arbptr];
        tempn = tempn->next;
        temp = temp->next;
    }

    return ansh;
}