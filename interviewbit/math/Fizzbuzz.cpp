#include <bits/stdc++.h>

using namespace std;

vector<string> fizzBuzz(int A)
{
    vector<string> ans(A);
    for (int i = 1; i <= A; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            ans[i] = "FizzBuzz";
        }
        else if (i % 3 == 0)
        {
            ans[i] = "Fizz";
        }
        else if (i % 5 == 0)
        {
            ans[i] = "Buzz";
        }
        else
            ans[i] = to_string(i);
    }
    return ans;
}
