#include <iostream>
#include <cstring>
using namespace std;

int stoint(char a[], int n)
{
    if (n == 0)
        return 0;

    return stoint(a, n - 1) * 10 + (a[n-1] - '0');
}

int main()
{
    char str[100] = "";
    cin.getline(str, 100);
    cout << stoint(str, strlen(str));
    return 0;
}