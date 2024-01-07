#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<int>> effort(n, vector<int>(m, 1e9));

        pq.push({0,0,0});
        effort[0][0] = 0;
        
        while(!pq.empty()) {
            int eff = pq.top()[0];
            int currRow = pq.top()[1];
            int currCol = pq.top()[2];
            pq.pop();

            if(currRow == n-1 && currCol == m-1) {
                return effort[currRow][currCol];
            }
            
            int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for(int d = 0; d < 4; d++) {
                int newRow = currRow + dir[d][0];
                int newCol = currCol + dir[d][1];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m ){
                    int newEff = max(abs(heights[newRow][newCol] - heights[currRow][currCol]), eff);
                    if(newEff < effort[newRow][newCol]) {
                        effort[newRow][newCol] = newEff;
                        pq.push({newEff, newRow, newCol});
                    }
                }
            }
        }

        return 0;
    }
};