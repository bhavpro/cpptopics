#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
    int cstoi(string a)
    {
        int x = 0;
        for (int i = 0; i < a.size(); i++)
        {
            x *= 10;
            x += (a[i] - '0');
        }
        return x;
    }

    int nod(int num)
    {
        int i = 0;
        do
        {
            i++;
            num /= 10;

        } while (num != 0);
        return i;
    }

    bool isvalidip(string &s, int i, int j, int k)
    {
        vector<string> temp(4, "");
        int n = s.size();
        temp[0] = s.substr(0, i + 1);
        temp[1] = s.substr(i + 1, j - i);
        temp[2] = s.substr(j + 1, k - j);
        temp[3] = s.substr(k + 1, n - 1 - k);
        for (int i = 0; i < 4; i++)
        {
            if (temp[i].size() > 3)
                return false;
            int num = cstoi(temp[i]);
            if (nod(num) != temp[i].size())
                return false;
            if (num < 0 || num > 255)
                return false;
            continue;
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        int n = s.size();
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                for (int k = j + 1; k < n - 1; k++)
                {
                    string str = "" + s.substr(0, i + 1) + "." + s.substr(i + 1, j - i) + "." + s.substr(j + 1, k - j) + "." + s.substr(k + 1, n - 1 - k);
                    cout << "\n"
                         << str << " " << i << j << k;
                    if (isvalidip(s, i, j, k))
                        ans.push_back(str);
                }
            }
        }
        return ans;
    }
};