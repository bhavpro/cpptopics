#include <bits/stdc++.h>

using namespace std;

int nTriang(vector<int> &A)
{
    int mod = 1e9 + 7;
    int n = A.size();
    long long count = 0;
    sort(A.begin(), A.end());
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = i + 2;
        while (k < n)
        {
            if (j < k)
                if (A[i] + A[j] > A[k]) // triangle formed
                {
                    count++;
                    count %= mod;
                }
                else // triangle not formed
                {
                    int mod = 1e9 + 7;
                    int n = A.size();
                    long long count = 0;
                    sort(A.begin(), A.end());
                    for (int i = 0; i < n - 2; i++)
                    {
                        int j = i + 1;
                        int k = i + 2;
                        while (k < n)
                        {
                            if (j < k)
                                if (A[i] + A[j] > A[k]) // triangle formed
                                {
                                    count++;
                                    count %= mod;
                                    k++;
                                }
                                else // triangle not formed
                                {
                                    if (j + 1 == k)
                                    {
                                        j++;
                                        k++;
                                        continue;
                                    }
                                    else // add rem triangles for k-1
                                    {
                                        int rem = (k - 1 - j) - 1;
                                        count += rem;
                                        count %= mod;
                                        continue;
                                    }
                                }
                        }
                        if (j + 1 != k)
                        {
                            count += k - 1 - j - 1;
                            count %= mod;
                        }
                    }
                    return count;
                    // add rem triangles for k-1
                    int rem = (k - 1 - j) - 1;
                    j = k - 1;
                    count += rem;
                    count %= mod;

                    continue;
                }

            k++;
        }
        if (j + 1 != k)
        {
            count += k - 1 - j - 1;
            count %= mod;
        }
    }
    return count;
}
