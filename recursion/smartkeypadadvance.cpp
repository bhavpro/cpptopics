#include <iostream>
#include <string>
#include <vector>

#define strv vector<string>

using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string table2 [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

strv getans(char str[], int n)
{
    // base
    if(n == 0)
    {
        strv final;
        final.push_back("");
        return final;
    }

    // rec
    string pad = table[str[0] - '0'];
    strv prev, final;
    prev = getans(str + 1, n - 1);
    for (int j = 0; j < pad.size(); j++)
    {
        char x = pad[j];
        for (int k = 0; k < prev.size(); k++)
        {
            string temp = "";
            temp.push_back(x);
            temp += prev[k];
            final.push_back(temp);
        }
    }
    return final;
}

bool ifcontain(string small, string large)
{
    bool lever = false;
    for (int i = 0; i < large.size(); i++)
    {
        if(large[i] == small[0] && ((i + small.size()) <= large.size()))
        {
            for (int j = 1; j < small.size(); j++)
            {
                if(small[j] != large[i + j])
                {
                    break;
                }
                if(j == small.size() - 1)
                {
                    if(small[j] == large[i + j])
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

strv findinarr(strv str)
{
    strv ans;
    bool tt = 0;
    string temp = "";
    string tablestr = "";
    int len = str.size();
    int strlen = 0;
    // choose a table2 member
    for (int i = 0; i < 11; i++)
    {
        tt = false;
        tablestr = table2[i]; // string from table is choosen
        // find a string from str
        for (int j = 0; j < len; j++)
        {
            temp = str[j]; // a string is choosen
            tt = ifcontain(temp, tablestr);
          //  cout << temp << " " << tablestr << " " << tt << "\n";
            if (tt == true)
            {
                ans.push_back(tablestr);
                break;
            }
        }
    }
    return ans;
}

int main()
{
    char str[11];
    int n;
    cin >> str;
    n = 0;
    while (str[n] != '\0')
    {
        n++;
    }
    strv arr = getans(str, n);
    arr = findinarr(arr);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}