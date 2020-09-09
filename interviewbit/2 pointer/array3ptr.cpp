#include <bits/stdc++.h>

using namespace std;

#define max3abs(a, b, c) max(max(abs(a), abs(b)), abs(c))

int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int i = 0, j = 0, k = 0;
    int minans = INT_MAX;
    int as = A.size(), bs = B.size(), cs = C.size();

    while (i < as - 1 || j < bs - 1 || k < cs - 1)
    {
        int maxans = max3abs(A[i] - B[j], B[j] - C[k], C[k] - A[i]);
        minans = min(minans, maxans);

        if (i < as - 1 && j < bs - 1 && k < cs - 1) // none reached end
            if (A[i] <= B[j] && A[i] <= C[k])
                i++;
            else if (B[j] <= A[i] && B[j] <= C[k])
                j++;
            else
                k++;
        else if (i == as - 1) // i reached end
            if (j == bs - 1)
                k++;
            else if (k == cs - 1)
                j++;
            else if (B[j] <= C[k])
                j++;
            else
                k++;
        else if (j == bs - 1) // j reached end
            if (k == cs - 1)
                i++;
            else if (A[i] <= C[k])
                i++;
            else
                k++;
        else if (k == cs - 1) // k reached end
            if (A[i] <= B[j])
                i++;
            else
                j++;
    }
    if (as == 1 && bs == 1 && cs == 1)
        return max3abs(A[0] - B[0], B[0] - C[0], C[0] - A[0]);
    return minans;
}

int minimizeop(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int i = 0, j = 0, k = 0;
    int minans = INT_MAX;
    int as = A.size(), bs = B.size(), cs = C.size();

    while (i < as && j < bs && k < cs)
    {
        int maxans = max3abs(A[i] - B[j], B[j] - C[k], C[k] - A[i]);
        minans = min(minans, maxans);

        if (A[i] <= B[j] && A[i] <= C[k])
            i++;
        else if (B[j] <= A[i] && B[j] <= C[k])
            j++;
        else
            k++;
    }
    if (as == 1 && bs == 1 && cs == 1)
        return max3abs(A[0] - B[0], B[0] - C[0], C[0] - A[0]);
    return minans;
}
