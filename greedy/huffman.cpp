#include <bits/stdc++.h>

using namespace std;

struct node
{
    char ch;
    int freq;
    node *left, *right;
};

struct compare
{
    bool operator()(node *a, node *b)
    {
        if (a->freq > b->freq)
        {
            return true;
        }
        return false;
    }
};

void fill(node *root, map<char, string> &en, map<string, char> &dec, string val)
{
    // base
    if (root->left == NULL && root->right == NULL)
    {
        if (val == "")
            val = "0";
        en[root->ch] = val;
        dec[val] = root->ch;
        return;
    }

    // rec
    fill(root->left, en, dec, val + "0");
    fill(root->right, en, dec, val + "1");
}

string encodeit(map<char, string> &encoder, string a)
{
    string ans = "";
    char cur = 0;
    int curcount = 0;

    for (int i = 0; i < a.size(); i++)
    {
        ans += encoder[a[i]];
    }

    return ans;
}

int main()
{
    string str;
    cin >> str;
    map<char, int> freq;
    priority_queue<node *, vector<node *>, compare> pq;
    for (int i = 0; i < str.size(); i++)
    {
        freq[str[i]]++;
    }
    for (pair<char, int> fp : freq)
    {
        node *temp = new node;
        temp->ch = fp.first;
        temp->freq = fp.second;
        temp->left = NULL;
        temp->right = NULL;
        pq.push(temp);
    }
    while (pq.size() > 1)
    {
        node *n1 = pq.top();
        pq.pop();
        node *n2 = pq.top();
        pq.pop();
        node *temp = new node;
        temp->ch = '\0';
        temp->freq = n1->freq + n2->freq;
        temp->left = n1;
        temp->right = n2;
        pq.push(temp);
    }
    node *root = pq.top();
    pq.pop();
    map<char, string> encoder;
    map<string, char> decoder;
    fill(root, encoder, decoder, "");
    string encoded = encodeit(encoder, str);
    cout << encoded << encoded.size();
    return 0;
}