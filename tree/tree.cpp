#include <bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
};

node *insert()
{
    int val;
    cin >> val;
    // base
    if (val == -1)
    {
        return NULL;
    }
    // rec
    node *root = new node;
    root->value = val;
    root->left = insert();
    root->right = insert();
    return root;
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

int replbysumchild(node *root)
{
    // base
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
    {
        return root->value;
    }

    // rec
    int temp = root->value;
    root->value = replbysumchild(root->left) + replbysumchild(root->right);
    return root->value + temp;
}

int main()
{
    freopen("input.txt", "r", stdin);
    node *root;
    root = insert();
    print(root);
    replbysumchild(root);
    cout << "\n";
    print(root);
    del(root);
    return 0;
}