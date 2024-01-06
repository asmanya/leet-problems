#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // adjacency list containing starting -> {destination, price}
        vector<pair<int,int>> adjList[n];

        // initializing adjacency list
        for(int i = 0; i < flights.size(); i++) {
            adjList[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        
        // queue format - {stops, node, price}
        queue<pair<int, pair<int,int>>> q;
        q.push({0,{src, 0}});

        // price array
        vector<int> prices(n, 1e9);
        prices[src] = 0;

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int price = q.front().second.second;
            q.pop();

            
            if(stops > k) continue;
            for(auto it : adjList[node]) {
                int adjNode = it.first;
                int cost = it.second;

                if(prices[adjNode] > price + cost) {
                    prices[adjNode] = price + cost;
                    q.push({stops + 1,{adjNode, price + cost}});
                }
            }   
        }

        if(prices[dst] == 1e9) {
            return -1;
        }

        return prices[dst];
    }
};