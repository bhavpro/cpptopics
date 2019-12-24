#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct circular
{
    int c, r, s, e;
};

bool compr(circular a, circular b)
{
    return a.e < b.e;
}

int main()
{
    int n, count = 1;
    circular x;
    vector<circular> cr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x.c;
        cin >> x.r;
        x.s = x.c - x.r;
        x.e = x.c + x.r;
        cr.push_back(x);
    }

    sort(cr.begin(), cr.end(), compr);
    x = cr[0];
    for (int i = 1; i < n; i++)
    {
        if(cr[i].s >= x.e)
        {
            x = cr[i];
            count++;
        }
    }
    cout << n - count;
}