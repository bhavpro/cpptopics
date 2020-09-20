#include <bits/stdc++.h>

using namespace std;

int distanceOfClosestRepeatedEntries(vector<string> &sentence)
{
    int minval = INT_MAX;
    unordered_map<string, int> lastind;
    for (int i = 1; i < sentence.size(); i++)
    {
        if (lastind[sentence[i]] > 0)
        {
            minval = min(minval, i - lastind[sentence[i]]);
        }
        else if (sentence[0] == sentence[i])
        {
            minval = min(minval, i);
        }
        lastind[sentence[i]] = i;
    }
    return minval == INT_MAX ? -1 : minval;
}