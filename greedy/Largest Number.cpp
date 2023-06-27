#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool sorter(string a, string b)
{
    string ab = a + b;
    string ba = b + a;
    vector<string> v;
    v.push_back(ab);
    v.push_back(ba);
    sort(v.begin(), v.end());
    if (v[0] != ab)
        return true;
    else
        return false;
}

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        // convert to string
        vector<string> vs;
        for (int x : nums)
            vs.push_back(to_string(x));

        // sort array
        sort(vs.begin(), vs.end(), sorter);

        // convert to string
        string str = "";
        for (string x : vs)
            str += x;
        // trim front 0
        while (str.size() > 1 && str[0] == '0')
            str = str.substr(1, str.size() - 1);
        return str;
    }
};