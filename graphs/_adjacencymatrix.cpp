#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// undirected
// uwnweighted

void print(vector<vector<bool>> b)
{
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
}

void set(vector<vector<bool>> &b, int v1, int v2)
{
    b[v1][v2] = 1;
    b[v2][v1] = 1;
}

int main()
{
    int v;
    cin >> v;
    vector<vector<bool>> b(v + 1, vector<bool>(v + 1, 0));

    set(b, 2, 3);
    set(b, 1, 4);
    set(b, 1, 5);

    cout << "\n";
    print(b);
}