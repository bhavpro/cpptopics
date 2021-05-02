#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next;
    node(int a) : val(a), next(NULL)
    {
    }
};

class ll
{
public:
    node *front;
    node *back;

    ll() { front = back = NULL; }
    ~ll()
    {
        while (front != NULL)
        {
            node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    void pushback(int a)
    {
        node *temp = new node(a);
        if (front == NULL)
        {
            front = temp;
            back = temp;
            return;
        }
        back->next = temp;
        back = temp;
    }

    void print()
    {
        node *f = front;
        while (f != NULL)
        {
            cout << f->val << " ";
            f = f->next;
        }
    }
};

void rearrange(ll &a)
{
    node *slow = a.front, *fast = a.front;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    bool odd = false;
    if (fast != NULL)
    {
        odd = true;
        slow = slow->next;
    }

    // reverse second ll
    node *s = slow;
    node *prev = NULL;
    node *next = s->next;
    while (s != NULL)
    {
        next = s->next;
        s->next = prev;
        prev = s;
        s = next;
    }
    slow = prev;
    fast = a.front;
    // s is front for 2nd ll
    node *n = new node(-1);
    node *todel = n;
    while (slow != NULL)
    {
        n->next = fast;
        n = fast;
        fast = fast->next;
        n->next = slow;
        n = slow;
        slow = slow->next;
    }
    if (odd)
    {
        n->next = fast;
        n = n->next;
    }

    n->next = NULL;
    a.front = todel->next;
    delete todel;
}

int main()
{
    int n;
    cin >> n;
    ll l;
    for (int i = 1; i <= n; i++)
        l.pushback(i);
    l.print();
    cout << "\n";
    rearrange(l);
    l.print();

    return 0;
}

// 1      2      3     4   5
// s,f   s       f,s       f