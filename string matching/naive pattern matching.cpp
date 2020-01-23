#include <iostream>
#include <string>

using namespace std;

int strpat(string str, string patt)
{
    int occur = 0;
    int plen = patt.length();
    int slen = str.length() - plen;
    for (int slide = 0; slide <= slen; slide++)
    {
        int i;
        for (i = 0; i < plen; i++)
        {
            if (str[i + slide] != patt[i])
                break;
        }
        if (i == plen)
        {
            occur++;
        }
    }
    return occur;
}

int main()
{
    string str, patt;
    /*  cin >> str;
    cin >> patt;*/
    str = "aakbaakbarkakba";
    patt = "ak";
    cout << "\n"
         << strpat(str, patt);
    return 0;
}