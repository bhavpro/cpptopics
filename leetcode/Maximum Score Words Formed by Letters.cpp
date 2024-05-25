#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    int ms;
    unordered_map<char, int> freq;
    void rec(vector<string> &words, vector<int> &score, int wi = 0, int ts = 0)
    {
        // base
        if (wi == words.size())
        {
            ms = ms >= ts ? ms : ts;
            return;
        }

        // rec
        rec(words, score, wi + 1, ts);
        const string &w = words[wi];
        int z = 0;
        int s = 0;
        bool b = false;
        for (; z < w.size(); z++)
        {
            if (freq.find(w[z]) == freq.end() || freq[w[z]] == 0)
            {
                b = true;
                break;
            }
            s += score[w[z] - 'a'];
            freq[w[z]]--;
        }
        if (!b)
            rec(words, score, wi + 1, ts + s);
        for (int i = 0; i < z; i++)
            freq[w[i]]++;
    }

public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        ms = 0;
        for (char c : letters)
            freq[c]++;

        rec(words, score);
        return ms;
    }
};