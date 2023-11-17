#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for(auto ch: s) {
            if(ch == '(' || ch == '[' || ch == '{') {
                myStack.push(ch);
            }
            else {
                if(myStack.empty()) {
                    return false;
                }
                char topChar = myStack.top();
                myStack.pop();
                if(ch == ')' && topChar != '(' ||
                    ch == ']' && topChar != '[' ||
                    ch == '}' && topChar != '{') {
                        return false;
                    }
            }
        }
        return myStack.empty();
    }
};