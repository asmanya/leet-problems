#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t index = haystack.find(needle);
        if(index != string::npos) {
            return index;
        }
        return -1;
    }
};