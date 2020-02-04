#include <iostream>
#include <vector>

using namespace std;

int robot(vector<vector<bool>> maze, int r = 0, int c = 0)
{
    static int memo[20][20];
    int endr = maze.size();
    int endc = maze[0].size();
    // base
    if (r + 1 == endr && c + 1 == endc)
    {
        memo[r][c] = 1;
        return 1;
    }

    // rec
    int down = r + 1 != endr ? (maze[r + 1][c] == false ? (memo[r + 1][c] == 0 ? robot(maze, r + 1, c) : memo[r + 1][c]) : 0) : 0;  // down
    int right = c + 1 != endc ? (maze[r][c + 1] == false ? (memo[r][c + 1] == 0 ? robot(maze, r, c + 1) : memo[r][c + 1]) : 0) : 0; // right
    memo[r][c] = down + right;
    return memo[r][c];
}

int robotdp(vector<vector<bool>> maze)
{
    int dp[20][20];
    int endr = maze.size(), endc = maze[0].size();
    for (int i = 0; i < endr; i++)
    {
        for (int j = 0; j < endc; j++)
        {
            // base
            if (maze[i][j] == false) // maze is blocked
            {
                dp[i][j] = 0;
                continue;
            }

            if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            // rec
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[endr - 1][endc - 1];
}

int main()
{
    int r, c, b;
    cin >> r >> c >> b;
    vector<vector<bool>> maze(r, vector<bool>(c, false));
    int rb, cb;
    for (int i = 0; i < b; i++)
    {
        cin >> rb >> cb;
        maze[rb][cb] = true;
    }
    cout << robot(maze);
    return 0;
}