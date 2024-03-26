#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void helper(int index, string s, vector<vector<string>> &res, vector<string> &temp) {
        
        if(index == s.size()) {
            res.push_back(temp);
            return;
        }

        for(int i = index; i < s.size(); i++) {
            if(isPalindrome(s, index, i)) {
                temp.push_back(s.substr(index, i - index + 1));
                helper(i + 1, s, res, temp);
                temp.pop_back();
            }
        }

    }

    bool isPalindrome(string s, int start, int end) {
        
        while(start <= end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;

    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;

        helper(0, s, res, temp);

        return res;
    }
};