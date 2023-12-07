#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<double, vector<double>, greater<double>> pq;
        vector<vector<int>> res;
        multimap<double, vector<int>> mp;
        int i = 0;

        for(auto& pair: points) {
            double ans = pow(pow(pair[0], 2) + pow(pair[1], 2), 0.5);
            pq.push(ans);
            mp.insert({ans, pair});
        }
        
        while(i < k) {
            double top = pq.top(); // contains a double value
            auto it = mp.find(top); // searching for the double value in map
            res.push_back(it->second);
            mp.erase(it);
            pq.pop();
            i++;
        }
        return res;
    }
};