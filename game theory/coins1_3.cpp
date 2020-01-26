// N coins
// A starts to pick
// can pick [1,3] coins in one turn
// A and B pick alternately

#include <iostream>
#include <unordered_set>

using namespace std;

int mex(unordered_set<int> s)
{
    int mex = 0;

    unordered_set<int>::iterator end = s.end();

    while (s.find(mex) != end)
    {
        mex++;
    }

    return mex;
}

int grundy(int n)
{
    // base
    if (n <= 2)
    {
        return n;
    }

    // rec
    unordered_set<int> a;
    for (int i = 1; i <= 3; i++)
    {
        a.insert(grundy(n - i));
    }
    return mex(a);
}

int main()
{
    int n;
    cin >> n;
    int g = grundy(n);

    if (g != 0)
    {
        cout << "player 1 wins";
    }
    else
    {
        cout << "player 2 wins";
    }

    return 0;
}