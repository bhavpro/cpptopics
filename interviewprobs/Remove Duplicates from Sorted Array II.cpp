int Solution::removeDuplicates(vector<int> &A)
{
    int n = A.size();
    if (n < 2)
        return n;
    int s = 1;
    for (int e = 2; e < n; e++)
    {
        if (A[s] == A[e] && A[s - 1] == A[e])
            continue;
        s++;
        A[s] = A[e];
    }
    return s + 1;
}
