#include <iostream>

using namespace std;

void next(int &r, int &c)
{
    c++;
    if (c == 9)
    {
        r++;
        c = 0;
    }
}

bool check(int a[][9], int num, int r, int c)
{
    // check current row and column
    for (int i = 0; i < 9; i++)
    {
        // row
        if(i != c && num == a[r][i])
            return false;

        // col
        if(i != r && num == a[i][c])
            return false;
    }

    // check current box
    int boxrow = r / 3;
    int boxcol = c / 3;
    boxrow *= 3;
    boxcol *= 3;
    for (int i = boxrow; i < boxrow + 3; i++)
    {
        for (int j = boxcol; j < boxcol + 3; j++)
        {
            if(a[i][j] == num && i != r && j != c)
                return false;
        }
    }
    return true;
}

void print(int a[9][9])
{
    cout << "\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

bool solve(int a[][9])
{
    static int r = 0;
    static int c = 0;

    // base
    // if we reach last element at pos 8,8 successfully , r will go to row 9 and column 0 , then print
    if(r == 9)
    {
        print(a);
        return true;
    }

    // rec
    // to place a number,position should be empty
    if(a[r][c] != 0)
    {
        next(r, c); // decide next value for r and c
        return solve(a);
    }

    // Now position is empty
    // we can enter numbers 1 to 9 at that position
    for (int i = 1; i <= 9; i++)
    {
        // we have to check that if i can be inserted
        bool checkifinserted = check(a, i, r, c);
        if(checkifinserted == true)
        {
            a[r][c] = i;
            int prer = r, prec = c; // current r and c
            next(r, c);
            bool inserted = solve(a);
            if(inserted == true)
            {
                return true;
            }
            //if inserted false
            a[r][c] = 0;
            r = prer;
            c = prec;
        }
    }
    return false;
}

int main()
{
    int a[9][9] =
        {
            {0, 3, 8, 0, 2, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1},
            {2, 0, 0, 0, 9, 0, 7, 0, 4},
            {0, 6, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 7, 0, 0, 0, 0, 4, 9},
            {0, 2, 0, 8, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 9, 0, 0, 7, 0, 0, 3},
            {0, 0, 0, 0, 0, 0, 6, 1, 5}
        };
    print(a);
    cout << "\n\n";
    solve(a);
    return 0;
}