#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int val;
    node *left;
    node *right;

    node() : val(0), left(NULL), right(NULL)
    {
    }

    node(int a) : val(a), left(NULL), right(NULL)
    {
    }

    node(int a, node *left, node *right) : val(a), left(left), right(right)
    {
    }
};

node *buildtree();
void invert(node *head);

class bt
{
public:
    node *head;

    bt() { head = NULL; }
    ~bt() { clear(head); };
    void clear(node *head);
    void build();
    void print();
    void invert();
    void itinvert();
};

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    bt a;
    a.build();
    a.print();
    a.itinvert();
    cout << "\n";
    a.print();
    return 0;
}

void bt::build()
{
    head = buildtree();
}

void bt::clear(node *head)
{
    if (head == NULL)
        return;
    clear(head->left);
    clear(head->right);
    delete head;
}

void bt::print()
{
    queue<node *> q;
    q.push(head);
    q.push(NULL);

    while (q.size() > 1)
    {
        node *ele = q.front();
        q.pop();
        if (ele == NULL)
        {
            q.push(NULL);
            cout << "\n";
            continue;
        }
        cout << ele->val << "\t";
        if (ele->left != NULL)
            q.push(ele->left);
        if (ele->right != NULL)
            q.push(ele->right);
    }
}

node *buildtree()
{
    int val;
    cin >> val;
    if (val == -1)
        return NULL;
    node *l = buildtree();
    node *r = buildtree();
    node *h = new node(val, l, r);
    return h;
}

void bt::invert()
{
    ::invert(head);
}

void invert(node *head)
{
    if (head == NULL)
        return;
    invert(head->left);
    invert(head->right);
    node *temp = head->left;
    head->left = head->right;
    head->right = temp;
}

void bt::itinvert()
{
    queue<node *> q;
    q.push(head);
    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            q.pop();
            continue;
        }
        node *l = q.front()->left;
        node *r = q.front()->right;
        q.front()->left = r;
        q.front()->right = l;
        q.pop();
        q.push(l);
        q.push(r);
    }
}