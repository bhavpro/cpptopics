#include <bits/stdc++.h>

using namespace std;

int convtominutes(string hm)
{
#define ihm(a) (int)(hm[a] - '0')
    return (ihm(0) * 10 + ihm(1)) * 60 + (ihm(3) * 10 + ihm(4));
}

class Solution {
  public:
    int timeDifference(vector<string>& times) {
          sort(times.begin(), times.end());
    int beg = convtominutes(*times.begin());
    int end = convtominutes(*prev(times.end()));
    int diff = min(end - beg, beg - end + 1440);
    for (int i = 1; i < times.size(); i++)
    {
        beg = convtominutes(times[i - 1]);
        end = convtominutes(times[i]);
        diff = min(diff, min(end - beg, beg - end + 1440));
    }
    return diff;
    }
};