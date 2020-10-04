#include <bits/stdc++.h>

using namespace std;

vector<string> gen(int n)
{
    vector<string> ans;
    ans.push_back("0");
    ans.push_back("1");
    for (int i = 2; i <= n; i++)
    {
        int n1 = ans.size();
        for (int j = 0; j < n1; j++)
            ans[j] = "0" + ans[j];

        for (int j = n1 - 1; j >= 0; j--)
        {
            string str = ans[j];
            str[0] = '1';
            ans.push_back(str);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v = gen(n);
    cout << "\n";
    for (string x : v)
        cout << x << "\n";
}