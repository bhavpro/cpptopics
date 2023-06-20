long long modder = 1e9 + 7;

class Solution
{
public:
    int numTrees(int n)
    {
        long long a[n + 1];
        a[0] = a[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            a[i] = 0;
            for (int j = 1; j <= i; j++)
            {
                a[i] = (a[i] + (a[j - 1] * a[i - j]) % modder) % modder;
            }
        }
        return a[n];
    }
};