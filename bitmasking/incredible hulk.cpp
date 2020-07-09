#include <iostream>

using namespace std;

int ans(int n)
{
    int x = 0;
    while (n != 0)
    {
        n = n & n - 1;
        x++;
    }
    return x;
}

int main()
{
    int n;
    cin >> n;
    cout << "\n"
         << ans(n);
}