#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(int i = 0; i < tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
        }

        priority_queue<int> pq;

        for(auto f : freq) {
            if(f) {
                pq.push(f);
            }
        }

        int time = 0;
        queue<pair<int, int>> q;

        while(!pq.empty() || !q.empty()) {
            time += 1;

            if(!pq.empty()) {
                int cnt = pq.top() - 1;
                pq.pop();
                if(cnt) 
                    q.push({cnt, time + n});
            }

            if(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }   
        }

        return time;
    }
};