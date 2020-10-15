#include <bits/stdc++.h>

using namespace std;

vector<string> generateParenthesis(int n)
{
    vector<string> paran;
    if (n == 0)
        return paran;
    paran.push_back("()");
    for (int i = 2; i <= n; i++)
    {
        vector<string> temp = paran;
        paran.clear();
        for (int i = 0; i < temp.size(); i++)
            paran.push_back("(" + temp[i] + ")");

        for (int i = 0; i < temp.size() - 1; i++)
        {
            paran.push_back(temp[i] + "()");
            paran.push_back("()" + temp[i]);
        }
        paran.push_back("()" + temp[temp.size() - 1]);
    }
    return paran;
}