#include <bits/stdc++.h>

using namespace std;

int countnaivematch(string &str, string &pat)
{
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == pat[0])
        {
            int k = i;
            for (int j = 0; j < pat.size(); j++)
            {
                if (str[k] != pat[j])
                {
                    break;
                }
                if (j == pat.size() - 1)
                {
                    count++;
                }
                k++;
            }
        }
    }
    return count;
}

int countrabinmatch(string &str, string &pat)
{
    int count = 0;
    if (str.size() < pat.size())
    {
        return 0;
    }
    int path = 0, strh = 0;
    bitset<1> cond;
    cond.set();
    for (int i = 0; i < pat.size(); i++)
    {
        path += pat[i];
        strh += str[i];
        if (str[i] != pat[i])
        {
            cond[0] = 0;
        }
    }
    if (cond[0] == 1)
    {
        count++;
    }

    int j = pat.size() - 1;
    for (int i = 1; i < str.size() - pat.size() + 1; i++)
    {
        j++;
        strh -= str[i - 1];
        strh += str[j];
        if (path == strh)
        {
            cond[0] = true;
            for (int k = 0; k < pat.size(); k++)
            {
                if (pat[k] != str[i + k])
                {
                    cond[0] = false;
                }
            }
            if (cond[0] == true)
            {
                count++;
            }
        }
    }
    return count;
}

int kmp(string &str, string &pat)
{
    // make reset table
    int pl = pat.size();
    int sl = str.size();
    vector<int> res(pl);
    res[0] = -1;
    int j = -1;
    // kkkkkk
    for (int i = 1; i < pl; i++)
    {
        j++;
        res[i] = j;
        while (j >= 0 && pat[i] != pat[j])
        {
            j = res[j];
        }
    }

    // do kmp
    for (int i = 0; i < sl; i++)
    {
        
    }
}

int main()
{
    string str, pat;
    cin >> str;
    cin >> pat;
    cout << "\n"
         << countnaivematch(str, pat);
    cout << "\n"
         << countrabinmatch(str, pat);
    cout << "\n"
         << kmp(str, pat);
    return 0;
}