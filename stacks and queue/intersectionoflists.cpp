#include <iostream>
#include <vector>

using namespace std;

struct interval
{
    int s, e;
};

vector<interval> inters(interval *a1, interval *a2, int n1, int n2)
{
    vector<interval> ans;
    for (int i = 0, j = 0; i < n1 && j < n2;)
    {
        if (a1[i].s <= a2[j].e || a2[j].s <= a1[i].e) // means some overlapping is there
        {
            ans.push_back({max(a1[i].s, a2[j].s), min(a1[i].e, a2[j].e)});
        }
        if (a1[i].e < a2[j].e)
            i++;
        else if (a1[i].e > a2[j].e)
            j++;
        else
        {
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    interval arr1[] = {{1, 3}, {5, 6}, {7, 9}};
    int n1 = 3;
    interval arr2[] = {{2, 3}, {5, 7}};
    int n2 = 2;

    vector<interval> ans = inters(arr1, arr2, n1, n2);
    for (interval it : ans)
        cout << it.s << " " << it.e << "\n";
    return 0;
}