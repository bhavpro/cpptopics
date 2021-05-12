#ifndef BT_HPP
#define BT_HPP

#include <iostream>
#include <vector>

using namespace std;

class bt
{
public:
    vector<int> t;
    bt();
    void incsize(int a);
    void rec(int *arr,int *arrend,int i);
    void build(int *arr,int n);

};

#endif