#include <bits/stdc++.h>

using namespace std;

bool check(string board[], int n = 8)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != 0 && board[i][j] == board[i][j - 1])
                return 0;
            if (j != n - 1 && board[i][j] == board[i][j + 1])
                return 0;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    string board[8];
    for (int i = 0; i < 8; i++)
        cin >> board[i];

    cout << (check(board) == 1 ? "YES" : "NO");

    return 0;
}