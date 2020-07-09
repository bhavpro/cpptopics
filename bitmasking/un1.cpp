#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int a1[] = {1, 1, 2, 3, 3};
int a2[] = {1, 1, 2, 3, 4, 4};
int a3[] = {1, 1, 1, 2, 2, 2, 3};

int n1 = 5;
int n2 = 6;
int n3 = 7;

int unique1()
{
    int sum = 0;
    for (int i = 0; i < n1; i++)
    {
        sum = sum ^ a1[i];
    }
    return sum;
}

void unique2()
{
    int sum = 0;
    for (int i = 0; i < n2; i++)
    {
        sum = sum ^ a2[i];
    }

    // get pos of first 1
    int temp = sum;
    int pos = 0;
    while (true)
    {
        if (temp & 1)
        {
            break;
        }
        temp >>= 1;
        pos++;
    } // we got pos of first set from left

    int mask = 1 << pos;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n2; i++)
    {
        if (a2[i] & mask)
        {
            sum2 = sum2 ^ a2[i];
        }
        else
        {
            sum1 = sum1 ^ a2[i];
        }
    }
    cout << sum1 << " " << sum2 << "\n";
}

int unique3()
{
    vector<bitset<32>> v;
    for (int i = 0; i < n3; i++)
    {
        v.push_back(a3[i]);
    }

    bitset<32> ans;
    for (int i = 0; i < 32; i++)
    {
        int count = 0;
        for (int j = 0; j < n3; j++)
        {
            count += v[j][i];
        }
        ans[i] = count % 3;
    }
    return ans.to_ulong();
}

int main()
{
    cout << unique1() << "\n";
    unique2();
    cout << unique3() << "\n";
    return 0;
}