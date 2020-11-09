#include <bits/stdc++.h>

using namespace std;

struct UndirectedGraphNode
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x){};
};

UndirectedGraphNode *rec(UndirectedGraphNode *node, UndirectedGraphNode *par , unordered_map<UndirectedGraphNode *, bool> &vis, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &trans)
{
    // rec
    UndirectedGraphNode *cur = new UndirectedGraphNode(node->label);
    trans[node] = cur;
    vis[node] = true;
    for (UndirectedGraphNode *ch : node->neighbors)
    {
        if (!vis[ch])
        {
            UndirectedGraphNode *temp = rec(ch, node, vis, trans);
            cur->neighbors.push_back(temp);
            temp->neighbors.push_back(cur);
        }
        else if (ch != par)
        {
            cur->neighbors.push_back(trans[ch]);
        }
    }
    return cur;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
    unordered_map<UndirectedGraphNode *, bool> vis;
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> trans;
    return rec(node, NULL, vis, trans);
}
