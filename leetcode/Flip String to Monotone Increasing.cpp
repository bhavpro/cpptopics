#include <string>
// #include <algorithm>

using namespace std;

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int n = s.size();
        int dp0to1r[n], dp1to0l[n];
        for (int i = 0; i < n; i++)
            dp0to1r[i] = dp1to0l[i] = 0;
        for (int i = 0; i < n; i++)
            if (i == 0)
                dp1to0l[0] = 0;
            else
                dp1to0l[i] = dp1to0l[i - 1] + (s[i - 1] == '1' ? 1 : 0);
        for (int i = n - 1; i >= 0; i--)
            if (i == n - 1)
                dp0to1r[i] = 0;
            else
                dp0to1r[i] = dp0to1r[i + 1] + (s[i + 1] == '0' ? 1 : 0);
        int m = n;
        for (int i = 0; i < n; i++)
            m = min(m, dp0to1r[i] + dp1to0l[i]);
        return m;
    }
};