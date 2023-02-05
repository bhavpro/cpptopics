
int Solution::removeDuplicates(vector<int> &A) {
    int n1 = A.size();
    int s = 0;
    for (int e = 1; e < n1; e++)
    {
        if (A[e] == A[s])
            continue;
        A[++s] = A[e];
    }
    return s + 1;
}