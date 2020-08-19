#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *cloneGraph(Node *node, unordered_map<int, Node *> &m)
{

    // base
    if (m[node->val] != NULL)
    {
        return m[node->val];
    }

    // rec
    Node *temp = new Node;
    temp->val = node->val;
    m[temp->val] = temp;
    for (Node *x : node->neighbors)
    {
        temp->neighbors.push_back(cloneGraph(x, m));
    }
    return temp;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> edget(n);
    for (int i = 0; i < edges.size(); i++)
    {
        edget[edges[i][0]].push_back(edges[i][1]);
        edget[edges[i][1]].push_back(edges[i][0]);
    }
    int minh = INT_MAX;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        // bfs
        queue<pair<int, int>> q;
        unordered_map<int, bool> vis;
        q.push({i, 0});
        vis[i] = true;
        int maxh = 0;
        while (!q.empty())
        {
            int h = q.front().second;
            int cur = q.front().first;

            q.pop();
            maxh = max(h, maxh);
            for (int edge : edges[cur])
            {
                if (!vis[edge])
                {
                    q.push({edge, h + 1});
                    vis[edge] = true;
                }
            }
        }
        if (minh == maxh)
        {
            ans.push_back(i);
        }
        if (minh > maxh)
        {
            minh = maxh;
            ans.resize(0);
            ans.push_back(i);
        }
    }
    return ans;
}

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
}