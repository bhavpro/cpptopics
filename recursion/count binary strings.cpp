#include <iostream>

using namespace std;

/*

n                 0    1    2   3   4


total numbers     1    2    3   5   8
(no 11)

no. of zeroes     1    1    2   3   5

this is because 0 will come after every binary digit without checking the last digit
for n = 2                       n = 3
00              =>          000  and  001
10              =>          100  and  101
01              =>          010

so in n-1 , we can add the count  for no. of zeroes and get next n;
because 1 can also come after the 0


also, number of zeroes for n-1 is total number in n-2

so f(n) = f(n-1) + f(n-2)
*/

long memo[91];

void cs()
{
    // base
    memo[0] = 1;
    memo[1] = 2;
    // rec dp
    for (int i = 2; i <= 90;i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
}

int main()
{
    int t, n;
    cin >> t;
    cs();
    while (t != 0)
    {
        cin >> n;
        cout << memo[n] << "\n";
        t--;
    }
    return 0;
}