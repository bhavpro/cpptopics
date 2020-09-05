#include <bits/stdc++.h>

using namespace std;

class large
{
    vector<int> num;

public:
    large();
    void mul(int a);
    string out();
};

large::large()
{
    num.push_back(1);
}

void large::mul(int a)
{
    int c = 0;
    long long temp = 0;
    int i = 0;
    while (i < num.size() || c != 0)
    {
        temp = num[i] * (a % 10);
        temp += c;
        if (i >= num.size())
            num.push_back(temp % 10);
        c = (temp / 10);
        i++;
    }
}

string large::out()
{
    string s = "";
    for (int i = num.size() - 1; i >= 0; i--)
        s += num[i];
    return s;
}

string solve(int A)
{
}

int main()
{
    large a;
    a.mul(5);
    a.mul(4);
    cout << a.out();
}