#include <bits/stdc++.h>

using namespace std;

#define FIO                          \
    ;                                \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(0);                      \
    cout.tie(0);

int minjump(int n, int &d, string &path)
{
    int i = 1;
    int nos = 0;
    while (i != n)
    {
        nos++;
        for (int j = i + d; j >= i; j--)
        {
            if (i + d >= n)
            {
                i = n;
                break;
            }
            if (j == i)
            {
                return -1;
            }
            if (path[j] == '1')
            {
                i = j;
                break;
            }
        }
    }
    return nos;
}

int main()
{
    FIO;
    int n, d;
    string path;
    path.push_back(' ');
    cin >> n >> d;
    string temp;
    cin >> temp;
    path += temp;
    cout << minjump(n, d, path);
    return 0;
}