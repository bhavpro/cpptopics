#include <bits/stdc++.h>

using namespace std;
void merge(int a[], int s1, int e1, int s2, int e2)
{
    int i = s1, j = s2, k = 0;
    int n1 = e1 - s1 + 1;
    int n2 = e2 - s2 + 1;
    int *ans = new int[n1 + n2];
    while (i <= e1 && j <= e2)
    {
        if (a[i] < a[j])
        {
            ans[k++] = a[i++];
        }
        else
        {
            ans[k++] = a[j++];
        }
    }

    while (i <= e1)
    {
        ans[k++] = a[i++];
    }

    while (j <= e2)
    {
        ans[k++] = a[j++];
    }

    // coping content of ans to a
    for (k = 0; k < n1 + n2; k++)
    {
        a[s1 + k] = ans[k];
    }

    delete[] ans;
}

void mergesort(int a[], int s, int e)
{
    // base
    if (s == e)
    {
        return;
    }

    // rec
    int mid = s + e;
    mid /= 2;
    mergesort(a, s, mid);
    mergesort(a, mid + 1, e);
    merge(a, s, mid, mid + 1, e);
}
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int *ar = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    sort(ar, ar + n);
    //   mergesort(ar, 0, n - 1);
    cout << ar[b] - ar[b - 1];
    delete[] ar;
    return 0;
}