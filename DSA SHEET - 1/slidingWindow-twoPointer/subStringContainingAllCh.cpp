#include<iostream>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int index_a = -1, index_b = -1, index_c = -1, count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a') {
                index_a = i;
            }
            else if(s[i] == 'b') {
                index_b = i;
            }
            else {
                index_c = i;
            }
            if(i > 1) {
                count += min(min(index_a, index_b), index_c) + 1;
            }
        }
        return count;
    }
};