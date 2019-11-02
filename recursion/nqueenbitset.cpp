#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int count = 0;

void nqueen( int n)
{
    static int r = 1;
    // base
    // if we successfully put a queen in last row, then print
    if(r == n + 1)
    {
        count++;
        return;
    }
    // rec
    int sum = 0, dif = 0;
    static bitset<30> d1, d2, col; // bitset is 2n-1
    for (int c = 1; c <= n; c++)
    {
        sum = r + c;
        dif = r - c + n - 1;
        if(col[c] == 1 || d1[sum] == 1 || d2[dif] == 1)
        {
            continue;
        }
        // check ith column for another queen and diagonals
        // if no queen then
        r += 1;
        d1[sum] = d2[dif] = col[c] = 1;
        nqueen(n);
        r -= 1;
        d1[sum] = d2[dif] = col[c] = 0;
    }
}

int main()
{
    int n;
    cin >> n;
    nqueen(n);
    cout<<count;
    return 0;
}