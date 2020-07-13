#include <iostream>

using namespace std;

int i = 1;

int main()
{
    int i = 2;
    {
        int i = 3;
        {
            int i = 4;JKI5
            cout << ::i;
        }
    }
    return 0;
}