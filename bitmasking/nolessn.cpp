#include <iostream>

using namespace std;

int main(int argc, const char **argv)
{
    int sum = 0;
    int n;
    int a[3]; // how many no less than n divided by a, b or c
    cin >> n >> a[0] >> a[1] >> a[2];
    n = n - 1;
    for (int i = 0; i < 3; i++)
    {
        sum += (n / a[i]);
    }
    sum -= n / (a[1] * a[0]);
    sum -= n / (a[2] * a[1]);
    sum -= n / (a[2] * a[0]);
    sum += n / (a[0] * a[1] * a[2]);
    cout << sum;
    return 0;
}