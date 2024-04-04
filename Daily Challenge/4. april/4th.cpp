#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, count = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') count++;
            else if(s[i] == ')') count--;
            if(count < 0) count = 0;

            ans = max(ans, count);
        }

        return ans;
    }
};