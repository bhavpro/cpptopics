#include <bits/stdc++.h>

using namespace std;

void checkMagazine(vector<string> magazine, vector<string> note)
{
    multiset<string> s;
    for (int i = 0; i < magazine.size(); i++)
    {
        s.insert(magazine[i]);
    }
    for (int i = 0; i < note.size(); i++)
    {
        auto ptr = s.find(note[i]);
        if (ptr == s.end())
        {
            cout << "No";
            return;
        }
        s.erase(ptr);
    }
    cout << "Yes";
}