#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        st.push(s[0]);
            
        for(int i = 1; i < s.size(); i++) {
            if(!st.empty() && (st.top() == s[i] + 32 || st.top() == s[i] - 32)) {
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};