#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int total(int ind, int last, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        if(ind == n-1) return matrix[ind][last];
        if(dp[ind][last] != -1) return dp[ind][last];

        int first = INT_MAX, second = INT_MAX, third = INT_MAX;
        if(last >= 0) {
            first = matrix[ind][last] + total(ind + 1, last - 1, matrix, dp);
        }
        second = matrix[ind][last] + total(ind + 1, last, matrix, dp);
        if(last < n) {
            third = matrix[ind][last] + total(ind + 1, last + 1, matrix, dp);
        }

        return dp[ind][last] = min(first, min(second, third));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minimumSum = INT_MAX, n = matrix.size();

        for(int last = 0; last < n; last++) {
            vector<vector<int>> dp(n, vector<int>(n, -1));
            minimumSum = min(minimumSum, total(0, last, matrix, dp));
        }
        return minimumSum;
    }
};