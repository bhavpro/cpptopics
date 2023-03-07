#include <vector>
using namespace std;

int modder = 1000007;

int coinchange2(vector<int> &A, int B)
{
    int n = A.size();
    vector<int> ans(B + 1, 0);
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < B + 1; j++)
        {
            if (j == 0)
                ans[j] = 1;
            else if (i == 0)
                ans[j] = 0;
            else
            {
                int temp = -1;
                temp = ans[j];
                if (j - A[i - 1] >= 0)
                    temp = (ans[j - A[i - 1]] + temp) % modder;
                ans[j] = temp;
            }
        }
    }
    return ans[B];
}
