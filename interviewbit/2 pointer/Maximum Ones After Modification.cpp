#include <vector>
using namespace std;

int solve(vector<int> &A, int B)
{
    int e = -1;
    int s = 0;
    int n = A.size();
    int noz = B;
    int cs = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
            if (noz == 0)
            {
                e = i - 1;
                break;
            }
            else
                noz--;
    }

    if (e == -1)
        return A.size();
    cs = e - s + 1;
    while (s < e)
    {
        // move e forward
        e++;
        while (e < n)
        {
            e++;
            if (A[e] == 0)
                break;
        }
        e--;

        // move s forward
        while (s < n)
        {
            if (A[s] == 0)
                break;
            s++;
        }
        s += 1;
        if (e - s + 1 > cs)
            cs = e - s + 1;
    }
    return cs;
}
