#include <iostream>
#include <string>

using namespace std;

void pitable(string &pat, int a[])
{
    int plen = pat.length();
    a[0] = -1;
    int j = -1;
    //****loop
    for (int i = 1; i < plen; i++)
    {
        j++;
        if (pat[i] != pat[j])
        {
            a[i] = j;
            j = a[j];
        }
        if (pat[i] == pat[j])
        {
            a[i] = j;
        }
    }
}

int isthere(string &str, string &pat, int reset[])
{
    int plen = pat.length();
    int slen = str.length();
    int j = 0;
    for (int i = 0; i < slen; i++)
    {
        if (str[i] != pat[j])
        {
            if (j == 0)
            {
                continue;
            }
            j = reset[j];
            i--;
            continue;
        }
        j++;
        if (j == plen)
            return i + 1 - plen;
    }
    return -1;
}

int main()
{
    string a, b;
    int reset[20];
    a = "abaaabcxabcxabxa";
    b = "abcxabx";
    pitable(b, reset);
    cout << isthere(a, b, reset);
    return 0;
}