#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &A, vector<int> &B)
{
    vector<int> a(A);
    int i = 0, j = 0, k = 0;
    int na = a.size();
    int nb = B.size();
    A.reserve(na + nb);
    A.resize(na + nb);
    while (i < na && j < nb)
    {
        if (a[i] <= B[j])
            A[k++] = a[i++];
        else
            A[k++] = B[j++];
    }
    while (i < na)
    {
        A[k++] = a[i++];
    }

    while (j < nb)
    {
        A[k++] = B[j++];
    }
}

void mergeinplace(vector<int> &A, vector<int> &B)
{
    int na = A.size();
    int nb = B.size();
    A.resize(na + nb);
    int i = na - 1;
    int j = nb - 1;
    int k = na + nb - 1;
    while (j >= 0)
    {
        if (i >= 0 && A[i] > B[j])
            A[k--] = A[i--];
        else
            A[k--] = B[j--];
    }
}

int main()
{
    vector<int> a, b;
    a.push_back(-2);
    a.push_back(3);
    b.push_back(-4);
    b.push_back(-2);
    merge(a, b);
    for (int x : a)
        cout << x << " ";
}