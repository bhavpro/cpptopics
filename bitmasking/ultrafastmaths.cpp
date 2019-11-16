#include <iostream>
#include <string>

using namespace std;

char xorchar(char a, char b)
{
    char x;
    x = a == '0' ? b == '0' ? '0' : '1' : b == '0' ? '1' : '0';
    return x;
}

string xorstring(string x, string y)
{
    for (int i = 0; i < x.size(); i++)
    {
        x[i] = xorchar(x[i], y[i]);
    }
    return x;
}

int main()
{
    int t;
    cin >> t;
    string x, y;
    while(t != 0)
    {
        cin >> x >> y;
        x = xorstring(x, y);
        cout << x << "\n";
        t--;
    }
    return 0;
}