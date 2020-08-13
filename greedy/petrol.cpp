#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> intpair;

bool compare(intpair a, intpair b)
{
    return a.first < b.first;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<intpair> distfuel;
        int len, begp;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            distfuel.push_back({x, y});
        }
        cin >> len >> begp;

        // logic

        for (int i = 0; i < n; i++)
        {
            distfuel[i] = {len - distfuel[i].first, distfuel[i].second};
        }
        sort(distfuel.begin(), distfuel.end(), compare);

        // go to city now
        int prev = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            // if can visit a city
            if (begp >= distfuel[i].first - prev)
            {
                pq.push(distfuel[i].second);
                prev = distfuel[i].first;
                begp -= distfuel[i].second;
            }
            else
            {
                if (!pq.empty())
                {
                    begp += pq.top();
                    pq.pop();
                    count++;
                    i--;
                }
                else
                {
                    count = -1;
                    break;
                }
            }
        }
        while (count != -1 && begp < len - distfuel[n - 1].first)
        {
            if (!pq.empty())
            {
                begp += pq.top();
                pq.pop();
                count++;
            }
            else
            {
                count = -1;
            }
        }
        cout << count << "\n";
    }
    return 0;
}