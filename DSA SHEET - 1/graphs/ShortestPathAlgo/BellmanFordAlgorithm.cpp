#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> BellmanFord(int V, vector<vector<int>>& edges, int src) {

        // Bellman Ford algorithm
        vector<int> dist(V, 1e9);

        // doing n-1 relaxations
        for(int i =0; i < V-1; i++) {
            for(auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // ends creating the final dist array

        // checking for neg cycle - doing one more relaxtion
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }
        
        return dist;
    }
};