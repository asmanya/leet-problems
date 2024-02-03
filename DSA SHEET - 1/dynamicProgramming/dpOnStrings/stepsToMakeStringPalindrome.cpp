#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
         int n = s.length();
        string t = "";
        for(auto ch : s) {
            t = ch + t;
        }

        int m = s.length();
        vector<int> prev(n + 1, 0), cur(n +1, 0);
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i-1] == t[j-1]) {
                    cur[j] = 1 + prev[j-1];
                } else {
                    cur[j] =  max(prev[j], cur[j-1]);
                }
            }
            prev = cur;
        }

        return n - prev[n];
    }
};