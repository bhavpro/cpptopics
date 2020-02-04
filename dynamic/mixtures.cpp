#include <iostream>
#include <vector>
#include <utility>
#include <climits>

#define INF INT_MAX

using namespace std;

pair<int, int> memo[20][20];

pair<int, int> minsmoke(vector<int> arr, int i, int j)
{
    // base
    if (i == j)
    {
        memo[i][j].first = arr[i];
        memo[i][j].second = 0;
        return memo[i][j];
    }

    // rec
    pair<int, int> one, two;
    int minsmoketillnow = INF;
    int mixtureval;
    for (int k = i + 1; k <= j; k++)
    {
        one = memo[i][k - 1].first == -1 ? minsmoke(arr, i, k - 1) : memo[i][k - 1];
        two = memo[k][j].first == -1 ? minsmoke(arr, k, j) : memo[k][j];
        int smoke = one.first * two.first + one.second + two.second;
        if (smoke < minsmoketillnow)
        {
            minsmoketillnow = smoke;
            mixtureval = one.first + two.first;
            mixtureval %= 100;
        }
    }
    memo[i][j].first = mixtureval;
    memo[i][j].second = minsmoketillnow;
    return memo[i][j];
}

int minsmokedp(vector<int> arr)
{
    pair<int, int> dp[20][20];
    int len = arr.size();

    pair<int, int> temp1, temp2;
    for (int j = 0; j < len; j++)
    {
        int k = j;
        for (int i = 0; i < len - j; i++)
        {
            // base
            if (i == k)
            {
                dp[i][k] = make_pair(arr[i], 0);
                k++;
                continue;
            }
            // rec

            temp1 = dp[i][k - 1];
            temp1.second = temp1.first * arr[k] + temp1.second;
            temp1.first = temp1.first + arr[k];
            temp1.first %= 100;

            temp2 = dp[i + 1][k];
            temp2.second = arr[i] * temp2.first + temp2.second;
            temp2.first = temp2.first + arr[i];
            temp2.first %= 100;

            dp[i][k] = temp1.second < temp2.second ? temp1 : temp2;
            k++;
        }
    }
    return dp[0][len - 1].second;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
            memo[i][j] = make_pair(-1, -1);
    }
    pair<int, int> temp = minsmoke(a, 0, n - 1);
    cout << temp.second;
    cout << "\n"
         << minsmokedp(a);
    return 0;
}