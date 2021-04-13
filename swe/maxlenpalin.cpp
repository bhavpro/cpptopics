#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int maxphash(const string &palin)
{
    int sum = 0;
    bool op = false;
    // create hash
    unordered_map<char, int> of, ef, tot;
    for (char x : palin)
        tot[x]++;

    for (pair<char, int> p : tot)
    {
        if (p.second & 1)
        {
            sum += p.second - 1;
            op = true;
        }
        else
        {
            sum += p.second;
        }
    }

    if (op)
        sum++;

    return sum;
}

int maxpset(const string &palin)
{
    struct ele
    {
        unordered_set<char> s;
        int count;

        void init()
        {
            count = 0;
        }

        void ins(char a)
        {
            // if already then inc count and remove ele;
            if (s.count(a))
            {
                s.erase(a);
                count += 2;
                return;
            }

            // else add ele
            s.insert(a);
        }

        int getmax()
        {
            int total = count;
            if (s.size() > 0)
                total++;
            return total;
        }
    };

    ele temp;
    temp.init();
    for (char x : palin)
    {
        temp.ins(x);
    }
    return temp.getmax();
}

int main()
{
    string palin = "aaavbbbbccd";
    cout << maxphash(palin) << "\n";
    cout << maxpset(palin);
    return 0;
}