#include <bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
};
void print(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() > 1)
    {
        node *troot = q.front();
        q.pop();
        if (troot == NULL)
        {
            cout << "\n";
            q.push(NULL);
            continue;
        }
        if (troot->left != NULL)
        {
            q.push(troot->left);
        }
        if (troot->right != NULL)
        {
            q.push(troot->right);
        }
        cout << troot->value << " ";
    }
}
void del(node *root)
{
    // base
    if (root == NULL)
    {
        return;
    }

    // rec
    del(root->left);
    del(root->right);
    delete root;
}

void insert(node *&root, int n)
{
    // base
    if (root == NULL)
    {
        root = new node;
        root->left = NULL;
        root->right = NULL;
        root->value = n;
        return;
    }

    // rec
    if (n <= root->value)
    {
        insert(root->left, n);
        return;
    }
    if (n > root->value)
    {
        insert(root->right, n);
    }
}

pair<node *, node *> findmax(node *par, node *root)
{
    // base
    if (root->right == NULL)
    {
        return make_pair(par, root);
    }

    // rec
    return findmax(root, root->right);
}

void delnode(node *parent, node *&root, int num)
{
    // base
    if (root == NULL)
    {
        return;
    }

    if (root->value == num)
    {

        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            return;
        }

        // 1 child
        if (root->left == NULL)
        {
            if (parent == NULL) // root node
            {
                node *temp = root;
                root = root->right;
                delete temp;
            }
            if (parent->left == root)
            {
                parent->left = root->right;
            }
            else
            {
                parent->right = root->right;
            }
            return;
        }

        if (root->right == NULL)
        {
            if (parent == NULL) // root node
            {
                node *temp = root;
                root = root->left;
                delete temp;
            }
            if (parent->left == root)
            {
                parent->left = root->left;
            }
            else
            {
                parent->left = root->right;
            }

            return;
        }

        // 2 child

        auto temp = findmax(root, root->left);
        node *par = temp.first;
        node *cur = temp.second;
        root->value = cur->value;
        delete cur;
        par->right = NULL;
        return;
    }

    // rec
    if (num < root->value)
    {
        delnode(root, root->left, num);
        return;
    }
    if (num > root->value)
    {
        delnode(root, root->right, num);
        return;
    }
}

list<int> ctoll(node *root)
{
    // base
    if (root == NULL)
    {
        return list<int>();
    }

    if (root->left == NULL && root->right == NULL)
    {
        list<int> l;
        l.push_back(root->value);
        return l;
    }

    // rec
    list<int> l1 = ctoll(root->left);
    list<int> l2 = ctoll(root->right);
    l1.push_back(root->value);
    for (int e : l2)
    {
        l1.push_back(e);
    }
    return l1;
}

int main()
{
    freopen("input1.txt", "r", stdin);
    node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(root, x);
    }
    print(root);
    cout << "\n\n";
    delnode(NULL, root, 9);
    print(root);
    del(root);
    list<int> ll = ctoll(root);
    cout << "\n\n\n";
    for (int e : ll)
    {
        cout << e << " ";
    }
    return 0;
}