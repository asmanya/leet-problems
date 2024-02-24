#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // creating adjacency list for meetings : person x -> {person y, time}
        vector<vector<pair<int, int>>> al(n);

        for(auto& meeting: meetings) {
            al[meeting[0]].push_back({meeting[1], meeting[2]});
            al[meeting[1]].push_back({meeting[0], meeting[2]});
        }

        // we will be performing bfs traversal using priority queue to get the meet that occures at the earliest
        // priority queue : {time, person}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});

        // creating a visited array to keep a track of people who knows the secret already
        vector<int> vis(n, 0);

        while(!pq.empty()) {

            // getting value of time and person to knows the secret
            auto [t, x] = pq.top();
            pq.pop();

            if(vis[x] == 1) continue;
            vis[x] = 1;

            // iterating through all the people y that person x can share the secret with
            for(auto& it: al[x]) {
                auto y = it.first;
                if(vis[y] == 1) continue;

                // if the person x knows the secret before the meeting with person y, it can be shared, thus pushed into pq
                if(it.second >= t) {
                    pq.push({it.second, y});
                }
            }
        }

        // getting all persons who know the secret
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 1) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};