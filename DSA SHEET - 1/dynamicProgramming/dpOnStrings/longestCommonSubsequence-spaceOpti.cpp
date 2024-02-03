#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<int> prev(n + 1, 0), cur(n +1, 0);

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i-1] == text2[j-1]) {
                    cur[j] = 1 + prev[j-1];
                } else {
                    cur[j] =  max(prev[j], cur[j-1]);
                }
            }
            prev = cur;
        }

        return prev[n];
    }
};

