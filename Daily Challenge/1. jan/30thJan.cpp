#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int calculate(stack<int>& st, string& c) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (c == "+") return b + a;
        if (c == "-") return b - a;
        if (c == "*") return b * a;
        return b / a;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        if (tokens.size() == 1 && !(tokens[0] == "+" || tokens[0] == "-" || tokens[0] == "*" || tokens[0] == "/")) {
            return stoi(tokens[0]);
        }

        if (tokens.size() == 2 && (tokens[0] == "+" || tokens[0] == "-" || tokens[0] == "*" || tokens[0] == "/") &&
            !(tokens[1] == "+" || tokens[1] == "-" || tokens[1] == "*" || tokens[1] == "/")) {
            return stoi(tokens[1]);
        }

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int temp = calculate(st, tokens[i]);
                st.push(temp);
            } else {
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};
