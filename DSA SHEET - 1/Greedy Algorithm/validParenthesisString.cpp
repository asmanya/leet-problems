#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> bracket, star;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                bracket.push(i);
            }
            else if(s[i] == '*') {
                star.push(i);
            }
            else {
                if(bracket.empty() && star.empty()) {
                    return false;
                }
                else if(!bracket.empty() && star.empty()) {
                    bracket.pop();
                }
                else if(!bracket.empty() && !star.empty()){
                    bracket.pop();
                }
                else {
                    star.pop();
                }
            }
        }
        while(!bracket.empty() && !star.empty()) {
            if(star.top() > bracket.top()) {
                bracket.pop();
                star.pop();
            }
            else {
                break;
            }
        }
        return bracket.empty();
    }
};