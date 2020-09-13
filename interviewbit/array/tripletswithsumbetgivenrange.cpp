#include <bits/stdc++.h>

using namespace std;

#define ld long double

void sweep(ld &a, ld &b, ld &c, ld val)
{
    ld sum = a + b + c;
    vector<ld> temp;
    temp.push_back(a);
    temp.push_back(b);
    temp.push_back(c);
    temp.push_back(val);
    sort(temp.begin(), temp.end());
    if (sum <= 1)
    {
        a = temp[1];
        b = temp[2];
        c = temp[3];
        return;
    }
    // sum >= 2

    a = temp[0];
    b = temp[1];
    c = temp[2];
}

void sortit(ld &a, ld &b, ld &c)
{
    vector<ld> temp;
    temp.push_back(a);
    temp.push_back(b);
    temp.push_back(c);
    sort(temp.begin(), temp.end());
    a = temp[0];
    b = temp[1];
    c = temp[2];
}

int solve(vector<string> &A)
{
    ld a = stold(A[0]), b = stold(A[1]), c = stold(A[2]), sum = 0;
    sortit(a, b, c);
    sum = a + b + c;
    if (sum > 1 && sum < 2)
    {
        return 1;
    }
    for (int i = 3; i < A.size(); i++)
    {
        ld val = stold(A[i]);
        sweep(a, b, c, val);
        sum = a + b + c;

        if (sum > 1 && sum < 2)
            return 1;
    }
    return 0;
}
