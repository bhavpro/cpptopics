#include <iostream>

using namespace std;

int countsetbits(int n)
{
    int count = 0;
    while (n != 0)
    {
        int p = n & (-n);
        n -= p;
        count++;
    }
    return count;
}

int main()
{
    cout << countsetbits(11);
    return 0;
}