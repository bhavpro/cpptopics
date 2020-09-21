#include <bits/stdc++.h>

using namespace std;

bool sortit(pair<int, bool> &a, pair<int, bool> &b)
{

    if (a.first == b.first)
        return a.second > b.second;
    return a.first < a.second;
}

bool hotel(vector<int> &arrive, vector<int> &depart, int K)
{
    vector<pair<int, bool>> times;
    for (int i = 0; i < arrive.size(); i++)
    {
        times.push_back({arrive[i], 0});
        times.push_back({depart[i], 1});
    }
    sort(times.begin(), times.end(),sortit);
    for (int i = 0; i < times.size(); i++)
    {
        if (times[i].second == 0)
            K--;

        if (K < 0)
            return false;

        if (times[i].second == 1)
            K++;
    }
    return true;
}
