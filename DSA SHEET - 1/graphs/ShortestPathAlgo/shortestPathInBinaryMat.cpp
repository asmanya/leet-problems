#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // n X m size dis array
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        // min heap - priority queue with {dist, {row , col}}
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        pq.push({0, {0, 0}});

        if(grid[0][0] == 1) return -1;
        if(n == 1 && m == 1) return 1;

        while(!pq.empty()) {
            int distance = pq.top().first;
            int currRow = pq.top().second.first;
            int currCol = pq.top().second.second;
            pq.pop();

            for(int i = -1; i < 2; i++) {
                for(int j = -1; j < 2; j++) {
                    int newRow = currRow + i;
                    int newCol = currCol + j;

                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    dist[newRow][newCol] > distance + 1 && grid[newRow][newCol] == 0) {
                        dist[newRow][newCol] = distance + 1;
                        pq.push({dist[newRow][newCol], {newRow, newCol}});
                    }
                }
            }
        }

        if(dist[n-1][m-1] == 1e9) {
            return -1;
        }

        return dist[n-1][m-1] + 1;
    }
};