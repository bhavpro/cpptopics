#include <bits/stdc++.h>

using namespace std;

vector<int> maxone(vector<int> &A, int B)
{
    int cun0 = 0;
    int i = -1;
    int maxc = 0;
    int count1 = 0;
    int s = 0, e = 0;
    for (int j = 0; j < A.size(); j++)
    {
        if (A[j] == 0)
        {
            cun0++;
            if (cun0 > B)
            {
                i++;
                while (A[i] != 0)
                    i++;
                j = i;
                count1 = 0;
                cun0 = 0;
                continue;
            }
        }
        count1++;
        if (maxc < count1)
        {
            maxc = count1;
            s = i + 1;
            e = j;
        }
    }
    vector<int> ans;
    for (int i = s; i <= e; i++)
        ans.push_back(i);
    return ans;
}

vector<int> maxonecopy(vector<int> &A, int B)
{
    int n = A.size();
    int i = 0, j = 0, maxc = 0, s = 0, e = 0, cun0 = 0;
    for (j = 0; j < n; j++)
    {
        if (A[j] == 0)
            cun0++;
        while (cun0 > B)
        {
            if (A[i] == 0)
            {
                cun0--;
            }
            i++;
        }
        if (j - i + 1 > maxc)
        {
            maxc = j + 1 - i;
            s = i, e = j;
        }
    }

    vector<int> v;
    for (int i = s; i <= e; i++)
        v.push_back(i);
    return v;
}

vector<int> maxoneop(vector<int> &A, int B)
{
    int i = 0;
    int maxc = 0;
    int cun0 = 0;
    int s = 0, e = 0;
    for (int j = 0; j < A.size(); j++)
    {
        if (A[j] == 0)
        {
            cun0++;
            while (cun0 > B)
            {
                if (A[i] == 0)
                    cun0--;
                i++;
            }
        }
        int c1 = j - i + 1;
        if (maxc < c1)
        {
            maxc = c1;
            s = i;
            e = j;
        }
    }

    vector<int> v;
    for (int i = s; i <= e; i++)
        v.push_back(i);
    return v;
}

int main()
{
    vector<int> a;
    int b = 2;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        a.push_back(str[i] - '0');
    }
    maxone(a, b);
}