#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string sub(int a, string str)
{
    int len = str.length();
    string temp;
    for (int i = 0; i < len; i++)
    {
        if (a & 1 == 1)
        {
            temp.push_back(str[i]);
        }
        a = a >> 1;
    }
    return temp;
}

vector<string> perm(string str)
{
    vector<string> ans;
    int len = str.length();
    len = pow(2, len);
    for (int i = 0; i < len; i++)
    {
        string temp = sub(i, str);
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;
    vector<string> s;
    s = perm(str);
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << "\n";
    }
    return 0;
}