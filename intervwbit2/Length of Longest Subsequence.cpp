#include <vector>
#include <iostream>
using namespace std;

int longestSubsequenceLength(const vector<int> &A)
{
    // lis A
    int n = A.size();
    int lis[n];
    for (int i = 0; i < n; i++)
        if (i == 0)
            lis[0] = 1;
        else
        {
            lis[i] = 1;
            for (int j = 0; j < i; j++)
                if (A[j] < A[i])
                    lis[i] = max(lis[i], lis[j] + 1);
        }

    // lds A
    int lds[n];
    for (int i = n - 1; i >= 0; i--)
    {
        lds[i] = 1;
        for (int j = i + 1; j < n; j++)
            if (A[j] < A[i])
                lds[i] = max(lds[i], lds[j] + 1);
    }

    // ans
    int maxv = 0;
    for (int i = 0; i < n; i++)
    {
        maxv = max(maxv, lds[i] + lis[i] - 1);
    }
    return maxv;
}

int main()
{
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        a.push_back(y);
    }
    cout << longestSubsequenceLength(a);
}