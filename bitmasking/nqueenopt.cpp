#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int n;
int done;
int count;
vector<bitset<100>> q(50, bitset<100>(0));

void solve(int c, int d1, int d2)
{
    // base
    if (c == done)
    {
        cout << "\n\n\n";
        count++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << (q[i][j] == 1 ? 'Q' : '_');
            }
            cout << "\n";
        }
        return;
    }

    // rec
    int safe = c | d1 | d2;
    safe = (~safe) & done;
    while (safe != 0)
    {
        int p = safe & (-safe);
        safe = safe - p;
        q[__builtin_popcount(c)][__builtin_ctz(p)] = 1;
        solve(p | c, (p | d1) << 1, (p | d2) >> 1);
        q[__builtin_popcount(c)][__builtin_ctz(p)] = 0;
    }
}

int main()
{
    cin >> n;
    count = 0;
    done = 1 << n;
    done--;
    solve(0, 0, 0);
    cout << "\n"
         << count;
    return 0;
}