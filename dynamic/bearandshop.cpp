#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n, k;
    vector<pair<int, int>> arr(n);
    int x, y;
    vector<string> strarr(n);
    while (t > 0)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            arr[i] = make_pair(x, y);
        }

        for (int i = 0; i < n; i++)
        {
            cin >> strarr[i];
        }

        cout << mindist(n, k, arr, strarr, 0);

        t--;
    }
    return 0;
}