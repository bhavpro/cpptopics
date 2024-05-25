#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
    unordered_map<int, int> pos;
    int ind(const int &x)
    {
        if (pos.find(x) == pos.end())
            return -1;
        return pos[x];
    }

public:
    int beautifulSubsets(vector<int> &nums, int k)
    {
        pos.clear();
        // fill pos
        for (int i = 0; i < nums.size(); i++)
            pos[nums[i]] |= (1 << i);

        // gen soln
        vector<int> dp;
        dp.push_back(0);
        for (int i = 0; i < nums.size(); i++)
        {
            const int &x = nums[i];
            int lpos = -1, rpos = -1;
            lpos = ind(x - k);
            rpos = ind(x + k);
            vector<int> temp;
            for (int subs : dp)
            {
                if (lpos != -1 && (subs & lpos) != 0)
                    continue;
                if (rpos != -1 && (subs & rpos) != 0)
                    continue;
                temp.push_back(subs | (1 << i));
            }
            dp.insert(dp.end(), temp.begin(), temp.end());
        }

        return dp.size() - 1;
    }
};

int main()
{
    vector<int> num = {1};
    int k = 1;
    Solution s;
    cout << s.beautifulSubsets(num, k);
    return 0;
}