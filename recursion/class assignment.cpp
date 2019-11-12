#include <iostream>

using namespace std;

int memo[51];

void ansdp()
{
    // base
    memo[0] = 0;
    memo[1] = 2;
    memo[2] = 3;

    // rec
    for (int i = 3; i < 51; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
}

int main()
{
    int t, n, total;
    cin >> t;
    total = t;
    ansdp();
    while (t != 0)
    {
        t--;
        cin >> n;
        cout <<"#" << total - t << " : " << memo[n] << "\n";
    }
    return 0;
}