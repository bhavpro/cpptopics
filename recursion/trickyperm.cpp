#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define strv vector<string>

using namespace std;

strv perm(char str[], int n)
{
    // base
    if( n == 0)
    {
        strv ans;
        ans.push_back("");
        return ans;
    }

    // rec
    strv temp, ans;
    string s, news;
    temp = perm(str + 1, n - 1);
    // add str[0]
    int p = 0;
    for (int i = 0; i < temp.size(); i++) // choose a string from vector
    {
        s = temp[i];
        for (int j = 0; j <= n - 1; j++) // determine pos of str[0]
        {
            p = 0;
            news = "";
            for (int k = 0; k <= n - 1; k++) // make news as new string
            {
                if(j == k)
                {
                    news.push_back(str[0]);
                    continue;
                }
                news.push_back(s[p]);
                p++;
            }
            ans.push_back(news);
        }
    }
    return ans;
}

void removedup(strv &str, strv &blank)
{
    static int i = 0;
    static int j = 1;
    static bool isrepeat = false;
    // base

    if(i == str.size() - 1)
    {
        blank.push_back(str[i]);
        return;
    }

    // rec
    if(j == str.size())
    {
        blank.push_back(str[i]);
        i++;
        j = i + 1;
        removedup(str, blank);
        return;
    }

    if(str[i] == str[j])
    {
        i++;
        j = i + 1;
        removedup(str, blank);
        return;
    }
    j++;
    removedup(str, blank);
}

bool lexo(string &a,string &b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i] < b[i])
            return true;
        if(a[i] > b[i])
            return false;
    }
    return false;
}

void sortit(strv &str)
{
    sort(str.begin(), str.end(), lexo);
}

int main()
{
    char arr[8];
    strv str, final;
    cin >> arr;
    int n;
    for (n = 0; n < 8; n++)
    {
        if(arr[n] == '\0')
        {
            break;
        }
    }
    str = perm(arr, n);
    if(str.size() > 1)
    {
        removedup(str, final);
        sortit(final);
    }
    else
    {
        final = str;
    }

    for (int i = 0; i < final.size(); i++)
    {
        cout << final[i] << "\n";
    }
    return 0;
}