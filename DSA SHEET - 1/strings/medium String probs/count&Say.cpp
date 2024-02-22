#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void count(string s, vector<pair<char, int>>& temp) {
        int count = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                temp.push_back({s[i - 1], count});
                count = 1;
            }
        }
        temp.push_back({s.back(), count});
    }

    string create(vector<pair<char, int>>& temp) {
        string s = "";
        for(auto pair : temp) {
            s += to_string(pair.second); 
            s += pair.first;
        }
        return s;
    }

public:
    string countAndSay(int n) {
        string s = "1";

        for(int i = 1; i < n; i++) {
            vector<pair<char, int>> temp;
            count(s, temp);
            s = create(temp);
        }
        
        return s;
    }
};