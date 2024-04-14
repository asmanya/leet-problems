#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    s[i] = '1';
                }
            }
        }

        while(!st.empty()) {
            s[st.top()] = '1';
            st.pop();
        }

        string res = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') continue;
            res += s[i];
        }

        return res;
    }
};