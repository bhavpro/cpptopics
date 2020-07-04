#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<bitset<32>> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        bitset<32> t = x;
        v.push_back(t);
    }

    bitset<32> ans;
    for (int i = 0; i <= 31; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += v[j][i];
        }
        sum %= 3;
        ans[i] = sum;
    }

    cout << ans.to_ulong();

    return 0;
}