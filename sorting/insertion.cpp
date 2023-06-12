#include <vector>
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void isort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j >= 0; j--)
        {
            if (a[j - 1] > a[j])
                swap(a[j], a[j - 1]);
            else
                break;
        }
    }
}

int main()
{
    int n = 4;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    isort(a);
    for (int x : a)
        cout << x << " ";
}