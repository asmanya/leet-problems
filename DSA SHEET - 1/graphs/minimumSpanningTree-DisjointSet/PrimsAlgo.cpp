#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int PrimsAlgo(int V, vector<vector<int>> adj[]) {

        // creating priority queue - min heap of type {wt, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});

        // incase we need to create the MST nodes array as well we can make
        // priority queue with three indeces {wt, node, parent};

        // creating vis array
        vector<int> vis(V, 0);
        int sum = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int weight = it.first;
            int node = it.second;

            if(vis[node]) continue;

            vis[node] = 1;
            sum += weight;

            for(auto it : adj[node]) {
                int adjNode = it[0];
                int wt = it[1];
                if(!vis[adjNode]) {
                    pq.push({wt, adjNode});
                }
            }
        }

        // returning only the total sum of MST
        return sum;
    }
};