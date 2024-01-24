#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev(n, 0);

        for(int i = 0; i < n; i++) {
            vector<int> curr(m, 0);
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    curr[0] = grid[0][0];
                    continue;
                }

                int first, second;
                if(i > 0)  {
                    first = grid[i][j] + prev[j];
                }
                if(j > 0) {
                    second = grid[i][j] + curr[j-1];
                }
                curr[j] = (i == 0) ? second : (j == 0) ? first : min(first, second);
            }
            prev = curr;
        }

        return prev[m-1];
    }
};