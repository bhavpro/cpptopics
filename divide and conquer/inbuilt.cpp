#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num = 6;
    cin >> num;
    vector<int> arr = {1, 2, 3, 4, 6, 6, 6, 6, 7, 8, 9};
    int n = arr.size();
    cout << (binary_search(arr.begin(), arr.end(), num) == 1 ? "PRESENT\n" : "NOT PRESENT\n");
    vector<int>::iterator l = lower_bound(arr.begin(), arr.end(), num);
    if (*l == num)
    {
        cout << "Lower Index : " << l - arr.begin() << "\n";
    }
    else
    {
        cout << "NOT PRESENT\n";
    }
    vector<int>::iterator u = upper_bound(arr.begin(), arr.end(), num);
    if (*(u - 1) == num)
    {
        cout << "Upper Index : " << (u - 1) - arr.begin() << "\n";
    }
    else
    {
        cout << "NOT PRESENT\n";
    }
    

    return 0;
}