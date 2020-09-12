#include <bits/stdc++.h>

using namespace std;

string minWindow(string S, string T)
{
    unordered_map<char, int> freqw;
    unordered_map<char, int> freqt;
    unordered_multiset<char> ms;
    for (int i = 0; i < T.size(); i++)
    {
        freqt[T[i]]++;
        ms.insert(T[i]);
    }

    int s = -1;
    int e = 0;
    for (; e < S.size(); e++)
    {
        char c = S[e];
        if (freqt[c])
        {
            freqw[c]++;
            ms.erase(c);
        }
    }

    for (int i = 0; i < S.size(); i++)
    {
        char c = S[i];
        // if char present in T , then take in map of window
        if (freqt[c])
            freqw[c]++;

        while (freqw[c] > freqt[c])
        {
        }
    }
}
