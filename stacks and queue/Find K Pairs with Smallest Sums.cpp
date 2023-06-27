#include <vector>
#include <queue>
using namespace std;

struct triplet
{
    int sum, a, b;
    bool operator<(const triplet &other) const
    {
        return sum < other.sum;
    }
};

struct pqs
{
    int k;
    priority_queue<triplet> pq;
    bool insert(triplet x)
    {
        if (pq.size() < k)
        {
            pq.push(x);
            return true;
        }
        if (pq.size() == k && pq.top().sum > x.sum)
        {
            pq.pop();
            pq.push(x);
            return true;
        }
        return false;
    }
};

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        pqs pq;
        pq.k = k;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (pq.insert({nums1[i] + nums2[j], nums1[i], nums2[j]}) == false)
                    break;
            }
        }
        vector<vector<int>> vect;
        while (!pq.pq.empty())
        {
            vector<int> v;
            triplet a = pq.pq.top();
            pq.pq.pop();
            v.push_back(a.a);
            v.push_back(a.b);
            vect.push_back(v);
        }
        return vect;
    }
};