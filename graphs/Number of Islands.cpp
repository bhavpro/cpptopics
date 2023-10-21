#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

int _ptoi(pii a, int c)
{
    return a.first * c + a.second;
}

pii _itop(int a, int c)
{
    pair<int, int> p;
    p.first = a / c;
    p.second = a % c;
    return p;
}

class dsu
{
public:
    vector<int> par;
    int n;

    dsu(int n)
    {
        par = vector<int>(n, -1);
        this->n = 0;
    }

    void insert(int x)
    {
        par[x] = x;
        n++;
    }

    int getp(int a)
    {
        if (par[a] == a)
            return a;
        return par[a] = getp(par[a]);
    }

    void join(int x, int y)
    {
        int X = getp(x);
        int Y = getp(y);
        if (X != Y)
        {
            n--;
            par[Y] = X;
        }
    }
};

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        dsu mydsu(r * c);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '1')
                {
                    int x = _ptoi(make_pair(i, j), c);
                    mydsu.insert(x);
                    if (i > 0 && grid[i - 1][j] == '1')
                        mydsu.join(x, _ptoi(make_pair(i - 1, j), c));
                    if (j > 0 && grid[i][j - 1] == '1')
                        mydsu.join(x, _ptoi(make_pair(i, j - 1), c));
                }
            }
        }

        return mydsu.n;
    }
};