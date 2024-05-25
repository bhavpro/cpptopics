#include <vector>
#include <string>
using namespace std;

struct Trienode
{
    char c;
    Trienode *vtnode[26];
    bool possend;

    Trienode(char c, bool possend = false) : c(c), possend(possend)
    {
        for (int i = 0; i < 26; i++)
            vtnode[i] = NULL;
    }
};

class Solution
{
    Trienode *root;
    vector<string> ans;
    void insert(Trienode *n, char *str)
    {
        if ((*str) == '\0')
        {
            n->possend = true;
            return;
        }

        Trienode *tp = n->vtnode[(*str) - 'a'];
        if (tp != NULL)
        {
            insert(tp, str + 1);
            return;
        }

        Trienode *next = NULL;
        while ((*str) != '\0')
        {
            Trienode *next = new Trienode(*str);
            n->vtnode[(*str) - 'a'] = next;
            n = next;
            str += 1;
        }
        n->possend = true;
    }

    void solve(Trienode *tnp, char *str, string sans)
    {
        if ((*str) == '\0' )
        {
            if( tnp->possend)
                ans.push_back(sans);
            return;
        }

        if (tnp->vtnode[(*str) - 'a'] != NULL )
            solve(tnp->vtnode[(*str) - 'a'], str + 1, sans + (*str));

        if (tnp->possend)
            solve(root, str, sans + ' ');
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        root = new Trienode('+');
        for (string word : wordDict)
            insert(root, (char *)word.c_str());
        solve(root, (char *)s.c_str(), "");
        return ans;
    }
};