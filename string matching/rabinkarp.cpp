#include <iostream>
#include <string>
#include <cmath>

#define ll long long int
#define hasher 3

using namespace std;

ll calculatehash(string &temp)
{
    ll val = 0;
    int len = temp.length();
    for (int i = 0; i < len; i++)
    {
        val += temp[i] * pow(hasher, i);
    }
    return val;
}

void modifyhash(ll &prev, char rem, char add, int len)
{
    prev += (add * pow(hasher, len)) - rem;
    prev /= hasher;
}

bool stringequal(string &first, string &second, int s1, int e1, int s2, int e2)
{
    if (e1 - s1 != e2 - s2)
    {
        cout << "string not equal as they are of different lengths";
        return false;
    }
    int j = s2;
    for (int i = s1; i < e1; i++)
    {
        if (first[i] != second[j++])
            return false;
    }
    return true;
}

int count(string str, string patt)
{
    int count = 0;
    int slen = str.length();
    int plen = patt.length();
    string temp;
    ll patthash = calculatehash(patt); // calc hash of pattern

    for (int i = 0; i < plen; i++) // make first substring
    {
        char x = str[i];
        temp.push_back(x);
    }

    ll beghash = calculatehash(temp); // calc first hash

    if (beghash == patthash) // check first hash
    {
        if (stringequal(str, patt, 0, plen, 0, plen) == true)
            count++;
    }

    for (int i = 1; i <= slen - plen; i++)
    {
        modifyhash(beghash, str[i - 1], str[i - 1 + plen], plen);
        if (beghash == patthash)
        {
            if (stringequal(str, patt, i, i + plen, 0, plen) == true)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    string str, patt;
    str = "apkaabhavyaakkavaal";
    patt = "ka";
    cout << count(str, patt);
    return 0;
}