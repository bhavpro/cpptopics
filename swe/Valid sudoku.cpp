#include <bits/stdc++.h>

using namespace std;

bool validSudoku(vector<vector<int>> &board)
{
    vector<unordered_map<int, bool>> row(9), col(9), part(9);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
                continue;

            int no = board[i][j];
            if (row[i][no] || col[j][no] || part[j / 3 + 3 * (i / 3)][no])
                return false;
            row[i][no] = 1;
            col[j][no] = 1;
            part[(j / 3) + 3 * (i / 3)][no] = 1;
        }
    }
    return true;
}