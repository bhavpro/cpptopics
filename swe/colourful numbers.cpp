#include <bits/stdc++.h>

using namespace std;

bool iscol(vector<int> &dig, unordered_map<int, bool> &prod)
{
    for (int i = 0; i < dig.size() - 1; i++)
    {
        int product = dig[i];
        for (int j = i + 1; j < dig.size(); j++)
        {
            product *= dig[j];
            if (prod[product])
                return 0;
            prod[product] = 1;
        }
    }
    return 1;
}

int colorful(int A)
{
    vector<int> dig;
    int temp = A;
    unordered_map<int, bool> prod;
    while (temp > 0)
    {
        int lastdig = temp % 10;
        if (prod[lastdig])
            return 0;
        prod[lastdig] = 1;
        dig.push_back(lastdig);
        temp /= 10;
    }

    return iscol(dig, prod);
}
