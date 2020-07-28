#include <bits/stdc++.h>

using namespace std;

int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
int n = 8;
struct node
{
    int value;
    node *left;
    node *right;
};
node *cons(int &i, int s, int e)
{
    // base
    if (s == e)
    {
        node *root = new node;
        root->value = pre[i];
        root->right = NULL;
        root->left = NULL;
        return root;
    }

    if (s > e)
    {
        i--;
        return NULL;
    }

    // rec
    node *root = new node;
    root->value = pre[i];
    int j = s;
    for (; j <= e; j++)
    {
        if (in[j] == pre[i])
            break;
    }
    root->left = cons(++i, s, j - 1);
    root->right = cons(++i, j + 1, e);
    return root;
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

int main()
{
    int i = 0;
    node *root = cons(i, 0, n - 1);
    print(root);
    del(root);
    return 0;
}