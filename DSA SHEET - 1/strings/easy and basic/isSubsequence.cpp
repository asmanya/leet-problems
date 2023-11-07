#include<iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int count = 0, n = s.size();
        size_t x = 0;
        for(auto ch: s){
            size_t pos = t.find(ch, x);
            if(pos != string::npos){
                count++;
                x = pos + 1;
            }
        }
        return count == n;
    }
};