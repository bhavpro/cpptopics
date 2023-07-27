#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

double calc(vector<int> &dist, int speed)
{
    double time = 0;
    for (int i = 0; i < dist.size() - 1; i++)
    {
        double t = (double)dist[i] / (double)speed;
        time += ceil(t);
    }
    double ans = ((double)(dist[dist.size() - 1]) / (double)speed);
    return ans + time;
}

class Solution
{
public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int maxdist = -1;
        for (int x : dist)
            if (x > maxdist)
                maxdist = x;

        double ms = hour - floor(hour) == 0 ? 0 : (double)dist[dist.size() - 1] / (hour - floor(hour));

        double maxtime = -1;
        int minspeed = -1;

        int s = 1;
        int e = max(maxdist, (int)ceil(ms));
        while (s <= e)
        {
            if (s + 1 == e)
            {
                double ctime = calc(dist, s);
                if (ctime == hour)
                    return s;
                if (ctime < hour && ctime > maxtime)
                {
                    maxtime = ctime;
                    minspeed = s;
                }

                ctime = calc(dist, e);
                if (ctime == hour)
                    return e;
                if (ctime < hour && ctime > maxtime)
                {
                    maxtime = ctime;
                    minspeed = e;
                }
                break;
            }
            int mid = s + e;
            mid >>= 1;
            if (mid == s)
                mid++;
            double ctime = calc(dist, mid);
            if (ctime == hour)
                return mid;
            if (ctime < hour && ctime > maxtime)
            {
                maxtime = ctime;
                minspeed = mid;
            }
            if (ctime < hour)
                e = mid;
            else
                s = mid;
        }
        return minspeed;
    }
};

int main()
{
    vector<int> dist{1, 3, 2};
    double hour = 2.7;
    Solution a;
    cout << a.minSpeedOnTime(dist, hour);
    return 0;
}