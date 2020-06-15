#include <iostream>
#include <vector>

using namespace std;

void multiply(vector<int> &ans, int num)
{
    int c = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        int a = ans[i] * num + c;
        ans[i] = a % 10;
        c = a / 10;
    }
    while (c > 0)
    {
        ans.push_back(c % 10);
        c /= 10;
    }
}

void bigfact(int n)
{
    vector<int> ans;
    ans.push_back(1);

    if (n > 1)
    {
        for (int i = 2; i <= n; i++)
        {
            multiply(ans, i); // ans = ans * i
        }
    }

    // cout ans
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
}

int main()
{
    int n;
    cin >> n;
    bigfact(n);
    return 0;
}