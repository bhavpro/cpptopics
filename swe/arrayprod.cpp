#include <bits/stdc++.h>

using namespace std;

vector<int> productExceptCurrentElement(vector<int> &arr)
{
    vector<int> ans;
    long long prod = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        prod *= arr[i];
    }

    for (int i = 0; i < arr.size(); i++)
    {
        ans.push_back(prod / arr[i]);
    }
    return ans;
}