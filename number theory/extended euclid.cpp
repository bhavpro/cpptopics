#include <iostream>
#include <math.h>

using namespace std;

pair<int, int> solvegcdeq(int a, int b)
{
    pair<int, int> temp;
    // init
    if (b > a)
    {
        temp = solvegcdeq(b, a);
        return make_pair(temp.second, temp.first);
    }

    // base
    if (b == 0)
    {
        return make_pair(1, 0);
    }

    // rec
    temp = solvegcdeq(b, a % b);
    int x = temp.first;
    int y = temp.second;
    temp.first = y;
    temp.second = x - floor(a / b) * y;
    return temp;
}

int main()
{
    int a, b;
    cin >> a >> b;
    pair<int, int> temp = solvegcdeq(a, b);
    cout << temp.first << " " << temp.second;
    return 0;
}