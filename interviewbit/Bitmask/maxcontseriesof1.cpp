#include <bits/stdc++.h>

using namespace std;

vector<int> maxone(vector<int> &A, int B)
{
    int i = 0;
    int countof0 = 0;
    int totalset = 0;
    int maxset = 0;
    for (int j = 0; j < A.size(); j++)
    {
        if (A[j] == 0)
        {
            if (countof0 == B)
            {
                maxset = max(maxset, totalset);
                totalset = 0;
                countof0 = 0;
            }
        }
    }
}
