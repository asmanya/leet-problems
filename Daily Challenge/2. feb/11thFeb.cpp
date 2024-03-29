#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> curr(m, vector<int>(m, 0)), ahead(m ,vector<int>(m, 0));

        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                if (j1 == j2)
                    ahead[j1][j2] = grid[n-1][j1];
                else
                    ahead[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e8; 

                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            int val;
                            
                            if (j1 == j2)
                                val = grid[i][j1];
                            else
                                val = grid[i][j1] + grid[i][j2];
                            
                            if(j1 + di >= 0 && j1 + di < m && j2 + dj >=0 && j2 + dj < m)
                                val += ahead[j1 + di][j2 + dj];
                            else 
                                val += -1e8;
                            
                            maxi = max(maxi, val);
                        }
                    }

                    curr[j1][j2] = maxi;
                }
            }
            ahead = curr;
        }
        
        return curr[0][m - 1];
    }
};