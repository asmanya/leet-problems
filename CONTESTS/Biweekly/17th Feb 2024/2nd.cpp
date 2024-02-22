#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char, int> mp;
        vector<int> hash(26, 0);
        
        for(auto ch : s){
            mp[ch]++;
            hash[ch - 'a']++;
        }
        
        int mx = 0;
        for(auto pair: mp){
            mx = max(mx, pair.second);
        }
        
        string res;
        for(auto ch : s){
            if(mp[ch] == 1 && hash[ch - 'a'] == mx) {
                res += ch;
            } else {
                mp[ch]--;
            }
        }
        
        return res;
    }
};