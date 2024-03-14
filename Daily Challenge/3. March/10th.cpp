#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        for(auto& it: nums1) {
            st.insert(it);
        }

        vector<int> ans;
        for(auto& it: nums2) {
            if(st.find(it) != st.end()) {
                ans.push_back(it);
                st.erase(it);
            }
        }

        return ans;
    }
};