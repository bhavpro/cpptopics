void Solution::merge(vector<int> &A, vector<int> &B)
{
    int xa = A.size();
    int xb = B.size();
    int xc = xa + xb;
    A.resize(xc);
    int i = xa - 1;
    int j = xb - 1;
    int k = xc - 1;
    while (j >= 0)
        if (i >= 0 && B[j] < A[i])
            A[k--] = A[i--];
        else
            A[k--] = B[j--];
}
