#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        stack<int> stk2;
        vector<int> res;
       
        if(stk.empty()) {
            stk.push(asteroids[0]);
        }
        for(int i = 1; i < asteroids.size(); i++) {
            if(asteroids[i] > 0) {
                stk.push(asteroids[i]);
            }
            else {
                while(!stk.empty() && stk.top() + asteroids[i] < 0 && stk.top() > 0) {
                    stk.pop();
                }
                if(stk.empty() || stk.top() < 0) {
                    stk.push(asteroids[i]);
                    continue;
                }
                if(stk.top() + asteroids[i] == 0) {
                    stk.pop();
                }
                else if(stk.top() + asteroids[i] > 0){
                    continue;
                }
            }
        }
        while(!stk.empty()) {
            stk2.push(stk.top());
            stk.pop();
        }
        while(!stk2.empty()) {
            res.push_back(stk2.top());
            stk2.pop();
        }
        return res;
    }
};