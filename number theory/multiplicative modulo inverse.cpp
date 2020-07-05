#include <iostream>
#include <utility>
#include <math.h>

#define intpair pair<int, int>

using namespace std;

intpair solveeuclideq(int a, int b)
{
    // init
    if (a < b)
    {
        intpair temp = solveeuclideq(b, a);
        return make_pair(temp.second, temp.first);
    }

    // base
    if (b == 0)
    {
        return make_pair(1, 0);
    }

    // rec
    intpair temp = solveeuclideq(b, a % b);
    intpair ans;
    ans.first = temp.second;
    ans.second = a / b;
    ans.second *= (-temp.second);
    ans.second += temp.first;
    return ans;
}

int main()
{
    int a, m;
    cin >> a >> m;
    intpair temp = solveeuclideq(a, m);
    cout << (temp.first + m) % m;
    return 0;
}