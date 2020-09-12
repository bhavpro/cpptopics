#include <bits/stdc++.h>

using namespace std;

int maxSubArray(const vector<int> &A) {
    int n = A.size();
    int maxsum = A[0];
    int sum = A[0];
    for (int i = 1; i < n; i++)
    {
        sum = max(sum + A[i], A[i]);
        maxsum = max(maxsum,sum);
    }
    return maxsum;
}
