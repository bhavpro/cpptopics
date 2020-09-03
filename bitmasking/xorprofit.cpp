#include <iostream>
#include <algorithm>

using namespace std;

int ans(int x, int y)
{
    int xora, maxi = 0;
    for (int i = x; i < y; i++)
    {
        for (int j = i + 1; j <= y; j++)
        {
            xora = i ^ j;
            maxi = max(maxi, xora);
        }
    }
    return maxi;
}

int main()
{
    int xx, x, yy, y, a, b;
    cin >> xx >> yy;
    if(xx < yy)
    {
        x = xx;
        y = yy;
    }
    else
    {
        x = yy;
        y = xx;
    }
    cout << ans(x, y);
    return 0;
}