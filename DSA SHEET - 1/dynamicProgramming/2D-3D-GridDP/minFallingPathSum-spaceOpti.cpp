#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, INT_MAX);

        for(int i = 0; i < n; i++) {
            prev[i] = matrix[0][i];
        }

        for(int i = 1; i < n; i++) {
            vector<int> curr(n, INT_MAX);
            for(int j = 0; j < n; j++) {
                if(j > 0) {
                    curr[j-1] = min(curr[j-1], prev[j] + matrix[i][j-1]);
                }
                curr[j] = min(curr[j], prev[j] + matrix[i][j]);
                if(j < n-1) {
                    curr[j+1] = min(curr[j+1], prev[j] + matrix[i][j+1]);
                }
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};