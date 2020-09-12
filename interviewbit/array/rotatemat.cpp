#include <bits/stdc++.h>

using namespace std;
void swap4(int &a, int &b, int &c, int &d)
{
    int temp = d;
    d = c;
    c = b;
    b = a;
    a = temp;
}

void rotate(vector<vector<int>> &A)
{
    int t = 0;
    int b = A.size() - 1;
    while (t < b)
    {
        for (int i = 0; i < b - t; i++)
        {
            swap4(A[t][t + i], A[t + i][b], A[b][b - i], A[b - i][t]);
        }
        t++;
        b--;
    }
}

/*
        t   b
  [31, 32, 228, 333]
 t [79, 197, 241, 246]
 b [77, 84, 126, 337]
  [110, 291, 356, 371]

[110 77 79 31 ] 
[291 197 84 32 ]
[356 241 126 228 ] 
[371 337 246 333 
*/
f