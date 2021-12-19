#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) 
    {

        unordered_multiset<char> st;
        unordered_multiset<int> :: iterator ptr;
        for(char &x: s)
            st.insert(x);
        for(char &x : t)
            if((st.find(x)) != st.end())
                st.erase(st.find(x));
            else
                return false;
        
        if(st.empty() )
            return true;
        return false;

        
    }
};