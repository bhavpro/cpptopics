#include <iostream>
#include <string>
#include <vector>

#define strv vector<string>

using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

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
    int len = arr.size();
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}