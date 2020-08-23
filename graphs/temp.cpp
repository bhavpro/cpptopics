#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solution(vector<int> &A, vector<int> &B, int N)
{
    // write your code in C++14 (g++ 6.2.0)
    unordered_map<int, int> freq;
    for (int i = 0; i < N; i++)
    {
        freq[A[i]]++;
        freq[B[i]]++;
    }
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int a = A[i];
        int b = B[i];
        count = max(freq[a] + freq[b] - 1, count);
    }
    return count;
}

int main()
{
    string s;
    cin >> s;
    cout << solution(s);
}