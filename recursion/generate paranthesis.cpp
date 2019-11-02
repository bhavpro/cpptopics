#include <iostream>
#include <string>
#include <vector>

using namespace std;

void gen(int n)
{
    static int i = 0; // no of brackets opened
    static int r = 0; // no of brackets open currently
    static string str = "";
    // base
    if(n == i)
    {
        string get = str;
        int k = r;
        while (k != 0)
        {
            get.push_back(')');
            k--;
        }
        cout << get << "\n";
        return;
    }

    // rec
    if(r == 0)
    {
        // open another bracket
        i++;
        r++;
        str.push_back('(');
        gen(n);
        str.pop_back();
        i--;
        r--;
        return;
    }
    if(r != 0 )
    {
        // can close a bracket
        r--;
        str.push_back(')');
        gen(n);
        str.pop_back();
        r++;

        // can open a bracket
        i++;
        r++;
        str.push_back('(');
        gen(n);
        str.pop_back();
        i--;
        r--;
    }
}

int main()
{
    int n;
    cin >> n;
    gen(n);
    return 0;
}