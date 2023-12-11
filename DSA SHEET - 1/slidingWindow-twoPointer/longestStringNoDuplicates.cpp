#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> indexMap(256, -1);
        int len = 0, right = 0, left = 0;

        while(right < s.size()) {
            if(indexMap[s[right]] != -1) left = max(left, indexMap[s[right]] + 1);
            indexMap[s[right]] = right;
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};