#include <vector>
#include <iostream>
using namespace std;

void ssort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        int si = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[si] > a[j])
                si = j;
        }
        int tmp = a[si];
        a[si] = a[i];
        a[i] = tmp;
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

    ssort(a);
    for (int x : a)
        cout << x << " ";
}