#include <bits/stdc++.h>

using namespace std;

bool isspruce(list<int> *childs, int n, int i = 1)
{
    // base
    if (childs[i].size() == 0) // leafnode
    {
        return true;
    }

    // rec
    int leafcount = 0;
    for (int ch : childs[i])
    {
        if (childs[ch].size() == 0)
        {
            leafcount++;
            continue;
        }
        if (!isspruce(childs, n, ch))
        {
            return false;
        }
    }
    if (leafcount >= 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isspruce1(vector<list<int>> &childs, int n, int i = 1)
{
    // base
    if (childs[i].size() == 0) // leafnode
    {
        return true;
    }

    // rec
    int leafcount = 0;
    for (int ch : childs[i])
    {
        if (childs[ch].size() == 0)
        {
            leafcount++;
            continue;
        }
        if (!isspruce1(childs, n, ch))
        {
            return false;
        }
    }
    if (leafcount >= 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    cin >> n;
     list<int> *children = new list<int>[n + 1];
   // vector<list<int>> children(n + 1);

    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        children[x].push_back(i);
    }
    cout << (isspruce(children, n) == 1 ? "Yes" : "No");
    delete[] children;
    return 0;
}