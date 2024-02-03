#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);

        stack<pair<int,int>> st;
        st.push({temperatures[n-1], n-1});
        res[n-1] = 0;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && temperatures[i] >= st.top().first) {
                st.pop();
            }

            if(st.empty()) {
                st.push({temperatures[i], i});
                continue;
            }

            if(st.top().first > temperatures[i]) {
                res[i] = st.top().second - i;
                st.push({temperatures[i], i});
            }
        }

        return res;
    }
};