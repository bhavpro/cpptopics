#include <string>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int prev = 1, cur = 1;
        if (s[0] >= '1' && s[0] <= '9')
            cur = 1;
        else
            return 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '0')
                if (s[i - 1] == '1' || s[i - 1] == '2')
                {
                    int temp = prev;
                    prev = cur;
                    cur = temp;
                }
                else
                    return 0;
            else if (s[i] >= '1' && s[i] <= '9')
                if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
                {
                    int temp = cur;
                    cur = cur + prev;
                    prev = temp;
                }
                else
                    prev = cur;
            else
                return 0;
        }
        return cur;
    }
};