#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node , vector<int> adjLs[], vector<int>& vis) {
        vis[node] = 1;
        for( auto it : adjLs[node]) {
            if(!vis[it]) dfs( it , adjLs , vis);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size() + 1;
        
        // converting adjaceny matrix into list

        vector<int> adjLs[size];
        for( int i = 0 ; i < size - 1; i++ ) {
            for( int j = 0 ; j < size - 1; j++ ) {
                if( isConnected[i][j] == 1 && i != j ) {
                    adjLs[i+ 1].push_back(j + 1);
                    adjLs[j + 1].push_back(i + 1);
                }
            }
        }

        // counting number of provinces

        vector<int> vis(size, 0);
        int count = 0;
        for(int i = 1; i < size; i++) {
            if(!vis[i]) {
                dfs( i , adjLs , vis );
                count++;
            }
        }
        return count;
    }
};