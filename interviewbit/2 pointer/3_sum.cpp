#include <bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    int i, j, k;
    i = 0;
    j = 1;
    k = 2;
    int sum = A[i] + A[j] + A[k];
    for (; k < A.size() && sum < B; k++)
    {
        sum = A[i] + A[j] + A[k];
    }
    for (; j < k && sum < B; j++)
    {
        sum = A[i] + A[j] + A[k];
    }
    for (; i < j && sum < B; i++)
    {
        sum = A[i] + A[j] + A[k];
    }
    if (sum <= B)
    {
        return sum;
    }
    int diff = sum - B;
    int temp = sum;
    while (sum > B && i >= 0)
    {
        i--;
        sum = A[i] + A[j] + A[k];
    }
    while (sum > B && j >= 0)
    {
        j--;
        sum = A[i] + A[j] + A[k];
    }
    while (sum > B && k >= 0)
    {
        k--;
        sum = A[i] + A[j] + A[k];
    }
    return sum;
}

int threeSumClosestbf(vector<int> &A, int B)
{
    int diff = INT_MAX;
    int mins;
    for (int i = 0; i < A.size() - 2; i++)
    {
        for (int j = i + 1; j < A.size() - 1; j++)
        {
            for (int k = j + 1; k < A.size(); k++)
            {
                long long sum = A[i] + A[j] + A[k];
                if (diff >= abs(B - sum))
                {
                    diff = abs(B - sum);
                    mins = sum;
                }
            }
        }
    }
    return mins;
}

int threeSumClosestop(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    int diff = INT_MAX;
    int minsum;
    for (int i = 0; i < A.size() - 2; i++)
    {
        int j = i + 1;
        int k = A.size() - 1;
        while (j < k)
        {
            int sum = A[i] + A[j] + A[k];
            int tempdiff = abs(B - sum);
            if (tempdiff == 0)
            {
                return sum;
            }
            if (tempdiff < diff)
            {
                diff = tempdiff;
                minsum = sum;
            }
            if (diff < 0)
            {
                k--;
            }
            if (diff > 0)
            {
                j++;
            }
        }
    }
    return minsum;
}
int threeSumClosest(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    int minsum = 1000000000, sum = 0;
    int diff = INT_MAX;
    for (int i = 0; i < A.size() - 2; i++)
    {
        int j = i + 1, k = A.size() - 1;
        while (j < k)
        {
            sum = A[i] + A[j] + A[k];
            int tempdiff = abs(B - sum);
            if (tempdiff < diff)
            {
                minsum = sum;
                diff = tempdiff;
            }
            if (sum > B)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return minsum;
}