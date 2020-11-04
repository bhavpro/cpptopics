#include <bits/stdc++.h>

using namespace std;

int findJudge(int N, vector<vector<int>> &trust)
{
    if (N == 1)
        return 1;
    unordered_map<int, int> freq;
    int jc = 0;
    int j = -1;
    for (int i = 0; i < trust.size(); i++)
    {
        freq[trust[i][1]]++;
        if (freq[trust[i][1]] == N - 1)
        {
            jc++;
            j = trust[i][1];
        }
    }
    if (jc > 1)
        return -1;
    for (int i = 0; i < trust.size(); i++)
        if (trust[i][0] == j)
            return -1;
    return j;
}