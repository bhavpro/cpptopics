#include <bits/stdc++.h>

using namespace std;

string kthstr(int k, string s)
{
    unordered_map<char, int> freq;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        freq[s[i]]++;
    }

    string temp = "";
    for (pair<char, int> charcount : freq)
    {
        if (charcount.second % k != 0)
            return "-1";
        int count = charcount.second / k;
        while (count--)
            temp += charcount.first;
    }
    string ans = "";
    for (int i = 1; i <= k; i++)
    {
        ans += temp;
    }
    return ans;
}

int main()
{
    int k;
    string s;
    cin >> k;
    cin >> s;
    cout << (k == 1 ? s : kthstr(k, s));
    return 0;
}