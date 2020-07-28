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
node *insert(int *arr, int s, int e)
{

    // base
    if (s > e)
    {
        return NULL;
    }

    if (s == e)
    {
        node *root = new node;
        root->value = arr[s];
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    // rec

    int mid = s + e;
    mid /= 2;
    node *root = new node;
    root->value = arr[mid];
    root->left = insert(arr, s, mid - 1);
    root->right = insert(arr, mid + 1, e);
    return root;
}

void getchild(node *root, int n)
{
    // base
    if (root->value == n)
    {
        cout << "Left -> " << (root->left == NULL ? -1 : (root->left)->value) << "\n";
        cout << "Right -> " << (root->right == NULL ? -1 : (root->right)->value) << "\n";
        return;
    }

    // rec
    if (root->left != NULL)
    {
        getchild(root->left, n);
    }
    if (root->right != NULL)
    {
        getchild(root->right, n);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    node *root = insert(arr, 0, n - 1);
    print(root);
    cout << "\n";
    return 0;
}