#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
struct Node {
    int no;
    int freq;
    Node(int a, int b) {
        no = a;
        freq = b;
    }
};

struct compare {
    bool operator() (Node const& a, Node const& b){
        return a.freq < b.freq;
    }
};

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;

    for(auto& x : nums) {
        mp[x]++;
    }
    
    priority_queue<Node, vector<Node>, compare> pq;
    for(auto it : mp) {
        pq.push(Node(it.first, it.second));
    }

    vector<int> ans;
    while(k--) {
        Node top = pq.top();
        pq.pop();
        ans.push_back(top.no);
    }
    return ans;
    }
};