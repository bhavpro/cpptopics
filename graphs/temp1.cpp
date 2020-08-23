#include <bits/stdc++.h>

using namespace std;

struct segt
{

    int n;
    vector<int> seg;
    segt(int n)
    {
        this->n = 4 * n + 1;
        seg = vector<int>(this->n);
    }

    void insert(vector<int> &a, int, int, int i = 1);
    int getmax(int i, int j, int s, int e, int ind = 1);
};

void segt::insert(vector<int> &a, int s, int e, int i = 1)
{
    // base
    if (s == e)
    {
        seg[i] = a[s];
    }

    // rec
    int mid = s + e;
    mid >> 1;
    insert(a, s, mid, i << 1);
    insert(a, mid + 1, e, (i << 1) + 1);
    seg[i] = max(seg[i << 1], seg[(i << 1) + 1]);
}

int segt::getmax(int i, int j, int s, int e, int ind = 1)
{
    // base
    if (i > e || j < s)
    {
        return 0;
    }

    if (i <= s && j >= e)
    {
        return seg[ind];
    }

    // rec
    int mid = s + e;
    mid >> 1;
    int m1 = getmax(i, j, s, mid, (ind << 1));
    int m2 = getmax(i, j, mid + 1, e, (ind << 1) + 1);
    return max(m1, m2);
}

int solution(vector<int> &H)
{
    // write your code in C++14 (g++ 6.2.0)
    int n = H.size();
    segt st(n);
    st.insert(H, 0, n - 1);
    int mini = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        int m1 = st.getmax(0, i, 0, n - 1);
        int m2 = st.getmax(i + 1, n - 1, 0, n - 1);
        mini = min(mini, m1 * (i + 1) + m2 * (n - i - 1));
    }
    return mini;
}

int main()
{

    return 0;
}

/*
Example test:   [3, 1, 4]
Output (stderr):
Segmentation Fault
RUNTIME ERROR (tested program terminated with exit code 1)

Example test:   [5, 3, 2, 4]
Output (stderr):
Segmentation Fault
RUNTIME ERROR (tested program terminated with exit code 1)

Example test:   [5, 3, 5, 2, 1]
Output (stderr):
Segmentation Fault
RUNTIME ERROR (tested program terminated with exit code 1)

Example test:   [7, 7, 3, 7, 7]
Output (stderr):
Segmentation Fault
RUNTIME ERROR (tested program terminated with exit code 1)

Example test:   [1, 1, 7, 6, 6, 6]
Output (stderr):
Segmentation Fault
RUNTIME ERROR (tested program terminated with exit code 1)

Detected some errors.*/