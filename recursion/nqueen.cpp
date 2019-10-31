#include <iostream>
#include <vector>

using namespace std;

void nqueen(vector<vector<bool>> a, int n)
{
    static int r = 1;
    // base
    // if we successfully put a queen in last row, then print
    if(r == n + 1)
    {
        cout << "\n";
        for (int row = 1; row <= n; row++)
        {
            for (int col = 1; col <= n; col++)
            {
                if(a[row][col] == 1)
                    cout << "Q ";
                else
                    cout << "- ";
            }
            cout << "\n";
        }
    }
    // rec
    bool queenplaced = 0;
    int sum = 0, dif = 0;
    for (int i = 1; i <= n; i++)
    {
        queenplaced = 0;
        sum = r + i;
        dif = r - i;
        for (int j = 1; j < r; j++) // j is row
        {
            for (int k = 1; k <= n; k++) // k is col
            {
                // column check
                if (a[j][i] == 1)
                {
                    queenplaced = 1;
                    break;
                }

                // left diagonal check
                if( j - k == dif && a[j][k] == 1)
                {
                    queenplaced = 1;
                    break;
                }

                // right diagonal check
                if( j + k == sum && a[j][k] == 1)
                {
                    queenplaced = 1;
                    break;
                }
                
            }
            if(queenplaced == 1)
            break;
        }
        if(queenplaced == 1)
            continue;
        // check ith column for another queen and diagonals
        // if no queen then
        a[r][i] = 1;
        r += 1;
        nqueen(a, n);
        r -= 1;
        a[r][i] = 0;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<bool>> a(n + 1, vector<bool>(n + 1, 0)); // n * n 2d vector from 1 to n
    nqueen(a, n);
    return 0;
}