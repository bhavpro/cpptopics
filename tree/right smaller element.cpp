#include <iostream>
#include <utility>

using namespace std;

class node
{
public:
    int value;
    int noels;
    node *left;
    node *right;

    node(int val = 0, int noels = 0, node *left = NULL, node *right = NULL) : value(val), noels(noels), left(left), right(right)
    {
    }
};

class bst
{
    void recins(int val, node *head, node *par, bool left, int &small);

public:
    node *head;
    bst()
    {
        head = NULL;
    }

    int insert(int val);
};

int bst::insert(int val)
{
    if (head == NULL)
    {
        head = new node(val);
        return 0;
    }
    int small = 0;
    recins(val, head, NULL, true, small);
    return small;
}

void getans(int *arr, int n, int *ans)
{
    bst tr;
    for (int i = n - 1; i >= 0; i--)
    {
        int ele = arr[i];
        ans[i] = tr.insert(ele);
    }
}

void bst::recins(int val, node *head, node *par, bool left, int &small)
{
    // base
    if (head == NULL)
    {

        head = new node(val);
        if (left)
            par->left = head;
        else
            par->right = head;

        return;
    }

    // rec

    if (val <= head->value)
    {
        head->noels++;
        recins(val, head->left, head, true, small);
        return;
    }

    small += (1 + head->noels);
    recins(val, head->right, head, false, small);
}

int main()
{
    int arr[] = {8, 5, 11, -1, 3, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    int *ans = new int[n];

    getans(arr, n, ans);

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    delete[] ans;

    return 0;
}