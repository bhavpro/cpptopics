#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector<string> findAndReplacePattern(const vector<string> &words, string pattern)
{
    vector<string> ans;
    int n = pattern.size();
    for (const string &str : words)
    {
        if (str.size() != n)
            continue;

        int mstop[256];
        int mptos[256];
        memset(mstop, 0, sizeof(mstop));
        memset(mptos, 0, sizeof(mptos));
        bool isans = true;

        for (int i = 0; i < n; i++)
        {
            char sh = str[i];
            char ch = pattern[i];
            if (!mstop[sh])
                mstop[sh] = ch;

            if (!mptos[ch])
                mptos[ch] = sh;

            if (mstop[sh] != ch || sh != mptos[ch])
            {
                isans = false;
                break;
            }
        }

        if (isans)
            ans.push_back(str);
    }
    return ans;
}

int main()
{
    vector<string> str;
    string pattern;
    str.push_back("abc");
    str.push_back("cde");
    str.push_back("zzz");
    pattern = "aaa";
    findAndReplacePattern(str, pattern);

    return 0;
}

/*

acc

cbb
xyx  

*/