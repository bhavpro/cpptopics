#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int n = 10000000;
bitset<10000005> arr;

vector<int> *bitsetsieve()
{
    vector<int> *ans = new vector<int>;
    arr.set();
    arr[0] = arr[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        (*ans).push_back(i);
        for (long long j = i * (long long)i; j <= n; j += i)
        {
            arr[j] = 0;
        }
    }
    return ans;
}

bool checklarge(long long num, vector<int> prime)
{
    if (num <= 10000000)
    {
        return arr[num] == 1 ? true : false;
    }
    else
        for (int i = 0; prime[i] * (long long)prime[i] <= num; i++)
            if (num % prime[i] == 0)
            {
                return false;
            }

    return true;
}

int main()
{
    vector<int> *a = bitsetsieve();
    long long num;
    cin >> num;
    cout << checklarge(num, *a);

    delete a;
    return 0;
}