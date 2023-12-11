#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0, j = 0, count = 0;
        int gLen = g.size(), sLen = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(i < sLen && j < gLen) {
            if(g[j] <= s[i]) {
                count++;
                i++;
                j++;
            } else {
                i++;
            }
        }
        return count;
    }
};