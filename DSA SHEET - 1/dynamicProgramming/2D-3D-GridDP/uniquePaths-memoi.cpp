#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int paths(int indx, int indy, vector<vector<int>>& dp) {
        if(indx == 0 || indy == 0) return 1;
        if(indx == 1 && indy == 1) return 2;
        if(dp[indx][indy] != -1) return dp[indx][indy];

        int first, second;
        if(indx >= 0) {
            first = paths(indx-1, indy, dp);
        }
        if(indy >= 0) {
            second = paths(indx, indy- 1, dp);
        }
        return dp[indx][indy] = first + second;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(m-1, n-1, dp);
    }
};