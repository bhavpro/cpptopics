#include <utility>
#include <string>
#include <stack>

using namespace std;

typedef pair<int, string> pis;

class Solution
{
public:
    string decodeString(string s)
    {
        string ans = "";
        stack<pis> ss;
        string num = "";
        for (char &ch : s)
        {
            if (ch == '[' || ch == ']') // if ch is opening or closing
            {
                if (ch == '[')
                {
                    int number = stoi(num);
                    num = "";
                    pis temp;
                    temp.first = number;
                    temp.second = "";
                    ss.push(temp);
                }
                else
                {
                    string temp = "";
                    while (ss.top().first--)
                        temp += ss.top().second;

                    ss.pop();
                    if (ss.empty())
                        ans += temp;
                    else
                        ss.top().second += temp;
                }
            }
            else if ('0' <= ch && ch <= '9') // if ch is number
            {
                num.push_back(ch);
            }
            else // ch is alpha
            {
                if (ss.empty())
                    ans.push_back(ch);
                else
                    ss.top().second.push_back(ch);
            }
        }
        return ans;
    }
};