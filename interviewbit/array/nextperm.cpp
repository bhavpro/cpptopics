#include <bits/stdc++.h>

using namespace std;

vector<int> Solution::nextPermutation(vector<int> &A) 
{
    if(A.size() == 1)
    return A;
    vector<int> a(A);
    int i;
    for (i = a.size() - 1; i >= 1; i--)
    {
        if (a[i - 1] < a[i])
        {
            i--;
            break;
        }
        if (i == 1)
        {
            reverse(a.begin(), a.end());
            return a;
        }
    }

    int minele = a[i+1];
    int minind = i+1;
    for (int j = i + 1; j < a.size(); j++)
    {
        if (a[j] > a[i] && minele > a[j])
        {
            minele = a[j];
            minind = j;
        }
    }

    int temp = a[minind];
    a[minind] = a[i];
    a[i] = temp;

    reverse(a.begin() + i + 1, a.end());
    return a;
}
