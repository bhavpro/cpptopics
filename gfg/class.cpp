#include <iostream>

using namespace std;

class p1
{
public:
    int a;
    int b;

    p1()
    {
        a = 0;
        b = 0;
    }

    p1(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
};

class p2
{
public:
    int a;
    int b;

    p2()
    {
        a = 1;
        b = 1;
    }

    p2(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
};

class b1 : public p1, public p2
{
public:
    b1() : p2(4, 4), p1(3, 3)
    {
    }
};

int main()
{
    b1 a;
    cout << a.p1::a << " " << a.p2::b;
    return 0;
}