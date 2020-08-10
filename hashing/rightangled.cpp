#include <bits/stdc++.h>

using namespace std;

struct cord
{
    int x;
    int y;
};

int noritr(const vector<cord> &points)
{
    int n = points.size();
    unordered_map<int, int> xc;
    unordered_map<int, int> yc;
    for (int i = 0; i < n; i++)
    {
        cord temp = points[i];
        xc[temp.x]++;
        yc[temp.y]++;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cord pt = points[i];
        count += ((xc[pt.x] - 1) * (yc[pt.y] - 1));
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<cord> points;
    for (int i = 0; i < n; i++)
    {
        cord temp;
        cin >> temp.x >> temp.y;
        points.push_back(temp);
    }
    cout << noritr(points);
    return 0;
}