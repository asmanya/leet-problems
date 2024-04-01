#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size(), ans = 0;

        for(int i = len - 1; i >= 0; i--) {
            if(s[i] == ' ' && ans != 0) {
                return ans;
            } else if(s[i] == ' ' && ans == 0){
                continue;
            }
            ans++;
        }

        return ans;
    }
};