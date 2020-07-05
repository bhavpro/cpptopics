#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void gen(string a)
{
    int n = a.size();
    for (int i = 0; i < pow(2,n); i++)
    {
        int j = i;
        string ans = "";
        int k = 0;
        while (j > 0)
        {
            if ((j & 1) == 1)
            {
                ans.push_back(a[k]);
            }
            j >>= 1;
            k++;
        }
        cout << ans << "\n";
    }
}

int main()
{
    string a;
    cin >> a;
    gen(a);
    return 0;
}