// number N to reduce to 0
// 3 piles  [4, 6, 8]
// moves -> [N/2] , [N/3] , [N/6]
// A starts to move
// A and B move alternately

#include <iostream>
#include <set>

using namespace std;

int mex(set<int> &s)
{
    int mexi = 0;
    set<int>::iterator ptr, end;
    ptr = s.begin();
    end = s.end();

    while (ptr != end)
    {
        if (*ptr != mexi)
        {
            break;
        }
        mexi++;
        ptr++;
    }

    return mexi;
}

int grundy(int n)
{
    // base
    if (n == 0)
        return 0;

    // rec
    int a, b, c;
    a = grundy(n / 2);
    b = grundy(n / 3);
    c = grundy(n / 6);
    set<int> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    return mex(s);
}

int main()
{
    int p[] = {0, 0, 2};
    int n = sizeof(p) / sizeof(int);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ grundy(p[i]);
    }

    cout << (ans != 0 ? "player 1 wins" : "player 2 wins");

    return 0;
}