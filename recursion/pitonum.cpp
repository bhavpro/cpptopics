#include <iostream>
#include <string>

using namespace std;

string pirep(string s)
{
    if (s.size() <= 0)
        return "";

    string str;
    if (s[0] == 'p' && (s.size() > 1 && s[1] == 'i'))
        str = "3.14" + pirep(s.substr(2, s.size() - 2));
    else
        str = s[0] + pirep(s.substr(1, s.size() - 1));
    return str;
}

int main()
{
    string s;
    getline(cin, s);
    cout << pirep(s);
    return 0;
}