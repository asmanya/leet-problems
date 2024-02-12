#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[j - 1] == str2[i - 1]) {
                    dp[j][i] = 1 + dp[j - 1][i - 1];
                } else {
                    dp[j][i] = max(dp[j - 1][i], dp[j][i - 1]);
                }
            }
        }

        string res = "";
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                res = str1[i - 1] + res;
                i--;
                j--;
            } else if (dp[i][j - 1] < dp[i - 1][j]) {
                res = str1[i - 1] + res;
                i--;
            } else {
                res = str2[j - 1] + res;
                j--;
            }
        }

        while (j > 0) {
            res = str2[j - 1] + res;
            j--;
        }

        while (i > 0) {
            res = str1[i - 1] + res;
            i--;
        }

        return res;
    }
};
