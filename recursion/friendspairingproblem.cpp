#include <iostream>

using namespace std;

long long memo[31];

/*
let we calculated for n-1

nth person enters

1. He can remain single means n-1 people can arrange in any number of ways (f(n-1))

2. He can pair up choosing 1 person from n-1 people  ((n-1) C 1)
   2 people paired up , so n-2 people arrange in f(n-2) ways

   total ([(n-1) C 1] * [f(n-2)] )
*/
void f()
{
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;

    for (int i = 3; i <= 30; i++)
    {
        memo[i] = memo[i - 1] + (memo[i - 2] * (i - 1));
    }
}

int main()
{
    int t, n;
    cin >> t;
    f();
    while (t != 0)
    {
        cin >> n;
        cout << memo[n] << "\n";
        t--;
    }
    return 0;
}