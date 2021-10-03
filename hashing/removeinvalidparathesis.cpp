#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> isthere;

bool validate(string str)
{
    int num = 0;
    for (char &x : str)
    {
        if (x == '(')
            num++;
        if (x == ')')
            num--;
        if (num < 0)
            return false;
    }
    return true;
}

void getparan(string &str, int extra, int clb, int pos = 0)
{
    // base
    if (extra == 0)
    {
        if (validate(str))
            isthere[str] = 1;

        return;
    }

    if (pos == str.size())
    {
        return;
    }
    // rec
    if (str[pos] == '(' || str[pos] == ')')
    {
        if (str[pos] == '(' && clb == false)
        {
            string strnew = str;
            strnew.erase(pos, 1);
            getparan(strnew, extra - 1, clb, pos);
        }
        else if (str[pos] == ')' && clb == true)
        {
            string strnew = str;
            strnew.erase(pos, 1);
            getparan(strnew, extra - 1, clb, pos);
        }
    }

    getparan(str, extra, clb, pos + 1);
}

int main()
{
    string str;
    //  cin.ignore();
    getline(cin, str);
    bool clb = true;
    int ex = 0;
    int op = 0, cl = 0;
    for (char &x : str)
    {
        if (x == '(')
            op++;
        if (x == ')')
            cl++;
    }

    if (op > cl)
    {
        ex = op - cl;
        clb = false;
    }
    else if (cl > op)
    {
        ex = cl - op;
        clb = true;
    }
    else
    {
        cout << str;
        return 0;
    }

    getparan(str, ex, clb);

    for (pair<string, bool> p : isthere)
        cout << p.first << "\n";

    return 0;
}