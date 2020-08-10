#include <bits/stdc++.h>

using namespace std;

int mins1(string str, string pat)
{
    int len1 = str.size();
    int len2 = pat.size();
    if (len1 < len2)
        return 0;

    unordered_map<char, int> patmap;
    unordered_map<char, int> window;
    int minl = INT_MAX;
    int count = 0;
    int smallind = -1;
    for (int i = 0; i < len2; i++)
    {
        patmap[pat[i]]++;
    }

    int l = 0;
    for (int r = 0; r < len1; r++)
    {
        char x = str[r];
        window[x]++;
        if (window[x] <= patmap[x])
            count++;

        if (count == len2)
        {

            while (patmap[str[l]] < window[str[l]])
            {

                window[str[l]]--;
                l++;
            }
            if (minl > r - l + 1)
            {
                minl = min(minl, r - l + 1);
                smallind = l;
            }
        }
    }
    return minl;
}

int main()
{
    string str = "adobecodebanc";
    string pat = "abc";
    cout << mins1(str, pat);
    return 0;
}