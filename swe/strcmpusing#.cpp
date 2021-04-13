#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a = "xy#z", b = "xzz#";
    int n = a.size();
    int i = n - 1, j = n - 1;
    while (i >= 0)
    {
        int count = 0;
        while (a[i] == '#' || count > 0)
        {
            if (a[i] == '#')
                count++;
            else
                count--;

            i--;
        }
        while (b[j] == '#' || count > 0)
        {
            if (b[j] == '#')
                count++;
            else
                count--;

            j--;
        }

        if (a[i] != b[j])
        {
            cout << "False";
            return 0;
        }
        i--;
        j--;
    }

    return 0;
}