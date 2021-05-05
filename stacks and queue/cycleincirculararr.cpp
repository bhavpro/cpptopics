#include <iostream>
#include <vector>

using namespace std;

bool iscycle(vector<int> &arr)
{
    int s = 0, f = 0;
    int n = arr.size();
    do
    {
        // nexts();
        [&s, &arr, n]() {
            s = (s + arr[s]) % n;
        }();
        // nextf()
        [&f, &arr, n]() {
            f = (f + arr[f]) % n;
            f = (f + arr[f]) % n;
        }();
    } while (s != f);

    bool pos = false, neg = false;

    do
    {
        if (arr[s] > 0)
            pos = true;
        else
            neg = true;
        [&s, &arr, n]() {
            s = (s + arr[s]) % n;
        }();

    } while (s != f);

    if (pos == neg)
        return false;
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    vector<int> arr;
    int n;
    cin >> n;
    arr.reserve(n);
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << iscycle(arr);
    return 0;
}