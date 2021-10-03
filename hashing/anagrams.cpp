#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<long> countSentences(vector<string> wordset, vector<string> sentences)
{
    vector<long> ans;
    unordered_map<string, vector<string>> ana;
    for (string &word : wordset)
    {
        string temp = word;
        sort(temp.begin(), temp.end());
        ana[temp].push_back(word);
    }

    for (string sent : sentences)
    {
        sent += " ";
        string word = "";
        int nos = 1;
        for (char &ch : sent)
        {
            if (ch == ' ')
            {
                sort(word.begin(), word.end());
                int option = ana[word].size();
                nos *= (option == 0 ? 1 : option);
                word = "";
                continue;
            }
            word += ch;
        }
        ans.push_back(nos);
    }
    return ans;
}

int main()
{
  //  freopen("input.txt", "r", stdin);
    vector<string> word;
    vector<string> sentence;
    int nw, ns;
    cin >> nw;
    for (int i = 0; i < nw; i++)
    {
        string w;
        cin >> w;
        word.push_back(w);
    }

    cin >> ns;
    for (int i = 0; i < ns; i++)
    {
        string s;
        cin.ignore();
        getline(cin, s);
        sentence.push_back(s);
    }

    vector<long> ans = countSentences(word, sentence);
    for (long x : ans)
        cout << x << "\n";
    return 0;
}