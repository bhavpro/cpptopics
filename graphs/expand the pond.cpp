#include <bits/stdc++.h>

using namespace std;

void maximizepond(vector<vector<bool>> &area)
{
}

int largest(vector<vector<bool>> &area)
{
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> area(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool temp;
            cin >> temp;
            area[i][j] = temp;
        }
    }
    maximizepond(area);
    cout << largest(area);
}