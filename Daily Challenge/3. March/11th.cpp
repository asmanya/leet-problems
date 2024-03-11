#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> sCount(26, 0);

        for(auto& ch: s) {
            sCount[ch - 'a']++;
        }

        vector<char> vec(order.size());
        for(int i = 0; i < order.size(); i++) {
            vec[i] = order[i];
        }

        string res;
        for(int i = 0; i < vec.size(); i++) {
            char ch = vec[i];
            while(sCount[ch - 'a'] != 0) {
                res += ch;
                sCount[ch - 'a']--;
            }
        }

        for(int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            while(sCount[ch - 'a'] != 0) {
                res += ch;
                sCount[ch - 'a']--;
            }
        }

        return res;
    }
};