#include <bits/stdc++.h>

using namespace std;

void countsort(vector<int> &blocks)
{
    int n = blocks.size();
    int count = 0;
    bitset<40004> a;
    a.reset();
    for (int i = 0; i < blocks.size(); i++)
    {
        a[blocks[i]] = 1;
    }
    blocks.erase(blocks.begin(), blocks.end());
    for (int i = 0; i < 40004; i++)
    {
        if (a[i] == 1)
        {
            count++;
            blocks.push_back(i);
        }
        if(count == n)
        {
            break;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int w, h, n;
        cin >> w >> h >> n;
        vector<int> rowblock(n + 2), colblock(n + 2);
        rowblock.resize(n);
        colblock.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> colblock[i] >> rowblock[i];
        }
        colblock.push_back(0);
        colblock.push_back(w + 1);
        rowblock.push_back(0);
        rowblock.push_back(h + 1);
        int maxw = 0, maxh = 0;
        countsort(rowblock);
        countsort(colblock);
        //sort(rowblock.begin(), rowblock.end());
        //sort(colblock.begin(), colblock.end());
        for (int i = 0; i < colblock.size() - 1; i++)
        {
            maxw = max(maxw, colblock[i + 1] - colblock[i] - 1);
            maxh = max(maxh, rowblock[i + 1] - rowblock[i] - 1);
        }
        cout << maxh * maxw << "\n";
    }
    return 0;
}