#include <bits/stdc++.h>

using namespace std;

const int N = 202;
#define vb vector<bitset<N>>
#define vvb vector<vector<bitset<N>>>

void createchessboard(vb &board, vvb &piece, int n, int p1, int p2, int p3, int p4)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = piece[p1][i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j + n] = piece[p2][i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i + n][j] = piece[p3][i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i + n][j + n] = piece[p4][i][j];
        }
    }
}

int check(vb &board, int n)
{
    bool p = false;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < (n << 1); i++)
    {
        p = !p;
        for (int j = 0; j < (n << 1); j++)
        {
            if (p != (bool)board[i][j])
                c1++;
            p = !p;
            if (p != (bool)board[i][j])
                c2++;
        }
    }
    return min(c1, c2);
}

int solve(vvb &piece, int n)
{
    vb chessboard = vb(2 * n);

    // rec
    int p1, p2, p3, p4;
    int mini = INT_MAX;
    for (int i = 0; i < 4; i++)
    {
        p1 = i;
        for (int j = 0; j < 4; j++)
        {
            if (j == p1)
                continue;

            p2 = j;
            for (int k = 0; k < 4; k++)
            {
                if (k == p1 || k == p2)
                    continue;

                p3 = k;
                for (int l = 0; l < 4; l++)
                {
                    if (l == p1 || l == p2 || l == p3)
                    {
                        continue;
                    }

                    p4 = l;
                    createchessboard(chessboard, piece, n, p1, p2, p3, p4);
                    mini = min(mini, check(chessboard, n));
                }
            }
        }
    }
    return mini;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vvb piece(4, vb(n + 1));
    for (int p = 0; p < 4; p++)
    {
        for (int i = 0; i < n; i++)
        {
            string temp;
            cin >> temp;
            reverse(temp.begin(), temp.end());
            piece[p][i] = bitset<N>(temp);
        }
    }
    cout << solve(piece, n);
    return 0;
}