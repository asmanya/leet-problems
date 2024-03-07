#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int r = s.size() - 1, l = 0;

        while(l < r) {
            if(s[l] != s[r]) break;
            
            char ch = s[l];
            while(l <= s.size() - 1 && s[l] == ch) l++;

            while(r >= 0 && s[r] == ch) r--;
        }

        return max(r - l + 1, 0);
    }
};