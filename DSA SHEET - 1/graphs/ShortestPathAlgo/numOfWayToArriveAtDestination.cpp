#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        
        vector<pair<int, int>>adj[n];
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<pair<long long, long long>>dist(n, {1e18, 0});
        dist[0]={0, 1};

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
        pq.push({0, 0});

        while(!pq.empty()){
            long long dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int adjNode=it.first;
                long long edgewt=it.second;
                if(dis+edgewt < dist[adjNode].first)
                {
                    dist[adjNode]={dis+edgewt, dist[node].second};
                    pq.push({dist[adjNode].first, adjNode});
                }
                else if(dis+edgewt == dist[adjNode].first)
                {
                    int count=dist[adjNode].second;
                    dist[adjNode]={dis+edgewt, (count+dist[node].second)%mod};
                }
            }
        }
        return dist[n-1].second;
    }
};