#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adjaceny list - { sourceNode -> {destNode, time}}
        vector<pair<int,int>> adjList[n+1];

        for(int i = 0; i < times.size(); i++) {
            adjList[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        // priority queue - {time, sourceNode}
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        // time vector
        vector<int> timeVec(n+1, 1e9);
        timeVec[k] = 0;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int node = it.second;
            
            for(auto it : adjList[node]) {
                int newNode = it.first;
                int reqTime = it.second;
                if(timeVec[newNode] > time + reqTime) {
                    timeVec[newNode] = time + reqTime;
                    pq.push({time + reqTime, newNode});
                }
            }
        } 

        int max = 0;
        for(int i = 1; i <= n; i++) {
            if(timeVec[i] > max) {
                if(timeVec[i] == 1e9){
                    return -1;
                }
                max = timeVec[i];
            }
        }
        return max;
    }
};