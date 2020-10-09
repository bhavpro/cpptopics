#include <bits/stdc++.h>

using namespace std;

bool isthere(vector<vector<int>> &matrix, int target, int sr, int er, int sc, int ec)
{
    // base
    if (sr + 1 == er && sc + 1 == ec)
        return target == matrix[sr][sc] ? 1 : (target == matrix[sr][sc + 1] ? 1 : (target == matrix[sr + 1][sc] ? 1 : (target == matrix[sr + 1][sc + 1] ? 1 : 0)));

    bool found = false;
    if (sr == er)
    {
        if (sc == ec)
            return target == matrix[sr][sc];
        else if (sc + 1 == ec)
            return target == matrix[sr][sc] ? 1 : (target == matrix[sr][ec] ? 1 : 0);
    }

    if (sc == ec)
    {
        if (sr + 1 == er)
            return target == matrix[sr][sc] ? 1 : (target == matrix[er][sc] ? 1 : 0);
    }

    // rec
    int mr = (sr + er) >> 1;
    int mc = (sc + ec) >> 1;

    if (matrix[sr][sc] <= target && target <= matrix[mr][mc] && isthere(matrix, target, sr, mr, sc, mc))
        found = true;

    if (mc + 1 <= ec && !found && matrix[sr][mc + 1] <= target && target <= matrix[mr][ec] && isthere(matrix, target, sr, mr, mc + 1, ec))
        found = true;

    if (mr + 1 <= er && !found && matrix[mr + 1][sc] <= target && target <= matrix[er][mc] && isthere(matrix, target, mr + 1, er, sc, mc))
        found = true;

    if (mr + 1 <= er && mc + 1 <= ec && !found && matrix[mr + 1][mc + 1] <= target && target <= matrix[er][ec] && isthere(matrix, target, mr + 1, er, mc + 1, ec))
        found = true;

    return found;
}

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        return isthere(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    }
};