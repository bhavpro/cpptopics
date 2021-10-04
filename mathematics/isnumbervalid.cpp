#include <iostream>

using namespace std;

enum state
{
    start,
    integer,
    decimal,
    unknown,
    afterdec
};

state getnext(state &st, char x)
{
    switch ((st))
    {
    case start:
    case integer:
        if (x >= '0' && x <= '9')
            return integer;
        else if (x == '.')
            return decimal;
        else
            unknown;
        break;

    case decimal:
    case afterdec:
        if (x >= '0' && x <= '9')
            return afterdec;
        else
            return unknown;
        break;

    case unknown:
        return unknown;
        break;
    }
    return unknown;
}

bool is_number_valid(string s)
{
    state st = start;
    if (s[0] == '+' || s[0] == '-')
        s = s.substr(1, s.size() - 1);
    for (char &x : s)
    {
        st = getnext(st, x);
    }
    if (st == decimal || st == unknown)
        return false;
    return true;
}

void test(const string s, bool expected)
{
    bool is_valid = is_number_valid(s);
    if (is_valid)
    {
        cout << s << " is valid." << endl;
    }
    else
    {
        cout << s << " is not valid." << endl;
    }
}

int main(int argc, char *argv[])
{
    test("4.325", true);
    test("4.325a", false);
    test("x4.325", false);
    test("4.32.5", false);
    test("4325", true);
    test("1.", false);
    test("1.1.", false);
    test("1.1.1", false);
    test("1.1.1.", false);
    test("+1.1.", false);
    test("+1.1", true);
    test("-1.1.", false);
    test("-1.1", true);
    test("", true);
}