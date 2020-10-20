#include <bits/stdc++.h>

using namespace std;

typedef map<pair<int, int>, bool> mapper;

int getcellno(int r, int c)
{
    return 3 * (r / 3) + (c / 3);
}

bool recsolve(vector<vector<char>> &board, mapper &row, mapper &col, mapper &cell, int i, int j)
{
    // base
    if (i == 9)
        return true;
    if (j == 9)
    {
        i++;
        j = 0;
        return recsolve(board, row, col, cell, i, j);
    }
    if (board[i][j] != '.') // number is there
    {
        return recsolve(board, row, col, cell, i, j + 1);
    }

    // rec

    // blank space
    {
        for (int num = 1; num <= 9; num++)
        {
            int cel = getcellno(i, j);
            if (!row[{i, num}] && !col[{j, num}] && !cell[{cel, num}])
            {
                row[{i, num}] = true;
                col[{j, num}] = true;
                cell[{cel, num}] = true;
                board[i][j] = num + '0';
                bool isdone = recsolve(board, row, col, cell, i, j + 1);
                row[{i, num}] = false;
                col[{j, num}] = false;
                cell[{cel, num}] = false;
                if (isdone)
                    return true;
                board[i][j] = '.';
            }
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>> &A)
{
    mapper row, col, cell;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (A[i][j] != '.')
            {
                int num = A[i][j] - '0';
                row[{i, num}] = 1;
                col[{j, num}] = 1;
                cell[{getcellno(i, j), num}] = 1;
            }
        }
    }
    recsolve(A, row, col, cell, 0, 0);
}

int main()
{
    cout << 3 * (5 / 3);
}