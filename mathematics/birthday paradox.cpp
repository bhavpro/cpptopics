#include <iostream>

using namespace std;

int bparadox(float p)
{
    int n = 1;
    float prob = 100;
    while (prob > p)
    {
        n++;
        prob = prob * (365 + 1 - n) / 365;
    }
    return n;
}

int main()
{
    float p; // atleast p % have same day bday
    cin >> p;
    cout << bparadox(100 - p);
    return 0;
}