#include <iostream>
#include <vector>
#include <utility>

#define intpair pair<int, int>

using namespace std;

intpair memo[20][20];

intpair score(vector<int> arr, int i, int j, bool turn)
{
    // base
    if (i + 1 == j)
    {
        memo[i][j] = make_pair(max(arr[i], arr[j]), min(arr[i], arr[j]));
        return memo[i][j];
    }

    // rec
    intpair a = memo[i + 1][j].first == -1 && memo[i + 1][j].second == -1 ? score(arr, i + 1, j, !turn) : memo[i + 1][j];
    intpair b = memo[i][j - 1].first == -1 && memo[i][j - 1].second == -1 ? score(arr, i, j - 1, !turn) : memo[i][j - 1];
    intpair temp;
    if (turn == true) // player 1 score
    {
        if (a.first < b.first)
        {
            // b is chosen
            temp.first = b.first + arr[j];
            temp.second = b.second;
        }
        else
        {
            // a is chosen
            temp.first = a.first + arr[i];
            temp.second = a.second;
        }
    }
    else // player 2 score
    {
        if (a.second < b.second)
        {
            // b is chosen
            temp.first = b.first;
            temp.second = b.second + arr[j];
        }
        else
        {
            // a is chosen
            temp.first = a.first;
            temp.second = a.second + arr[i];
        }
    }
    memo[i][j] = temp;
    return temp;
}

void pairintdpchecker(vector<int> a, intpair dp[20][20])
{
    cout << "\n\n";
    cout << "   ";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "    ";
    }
    cout << "\n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
        for (int j = 0; j < a.size(); j++)
        {
            cout << dp[i][j].first << "," << dp[i][j].second << "  ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

intpair scoredp(vector<int> arr)
{
    int turn = true;
    int length = arr.size();
    intpair dp[20][20];

    for (int k = 1; k < length; k++)
    {
        int j = k;
        for (int i = 0; i < length - k; i++)
        {
            // base
            if (i + 1 == j)
            {
                dp[i][j] = make_pair(max(arr[i], arr[j]), min(arr[i], arr[j]));
                j++;
                continue;
            }

            // rec

            intpair a = dp[i][j - 1]; // left
            intpair b = dp[i + 1][j]; // down
            if (turn == true)         // player 1 turn
            {
                if (a.first < b.first)
                {
                    // b chosen
                    b.first += arr[i];
                    dp[i][j] = b;
                }
                else
                {
                    // a chosen
                    a.first += arr[j];
                    dp[i][j] = a;
                }
            }
            else // player 2 turn
            {
                if (a.second < b.second)
                {
                    // b chosen
                    b.second += arr[i];
                    dp[i][j] = b;
                }
                else
                {
                    // a chosen
                    a.second += arr[j];
                    dp[i][j] = a;
                }
            }
            j++;
        }
        turn = !turn;
    }
    pairintdpchecker(arr, dp);
    return dp[0][length - 1];
}

int main()
{
    vector<int> arr(4);
    arr[0] = 4;
    arr[1] = 9;
    arr[2] = 3;
    arr[3] = 7;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            memo[i][j] = make_pair(-1, -1);
        }
    }
    intpair temp = score(arr, 0, arr.size() - 1, true);
    cout << temp.first << " " << temp.second;
    intpair temp1 = scoredp(arr);
    cout << "\n"
         << temp1.first << " " << temp1.second;
    return 0;
}