#include <bits/stdc++.h>

using namespace std;

bool sortit(string a, string b)
{
    int x = a.size();
    int y = b.size();
    return x <= y;
}

int maxProduct(vector<string> &words)
{
    sort(words.begin(), words.end(), sortit);
    int a = 0, b = 0;
    int prev, cur;
    int maxl = 0;
    int n = words.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (maxl != 0)
            return maxl;
        for (int j = i - 1; j >= 0; j--)
        {
            if (maxl != 0)
                return maxl;
            a = words[i].size();
            b = words[j].size();
            prev = 0;
            cur = 0;
            for (int k = 0; k < a; k++)
            {
                int alpno = words[i][k] - 'a';
                prev = prev | (1 << alpno);
            }
            for (int k = 0; k < b; k++)
            {
                int alpno = words[j][k] - 'a';
                cur = cur | (1 << alpno);
            }
            if (!(cur & prev))
            {
                maxl = max(maxl, a * b);
            }
        }
    }
    return maxl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    vector<string> words;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        words.push_back(temp);
    }
    cout << maxProduct(words);
}