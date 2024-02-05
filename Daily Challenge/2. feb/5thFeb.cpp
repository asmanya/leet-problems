#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int,int>> umap;

        // char - > freq, ind

        for(int i = 0; i < s.size(); i++) {
            umap[s[i]].first++;
            umap[s[i]].second = i;
        }

        for(int i = 0; i < s.size(); i++) {
            if(umap[s[i]].first == 1) {
                return umap[s[i]].second;
            }
        }

        return -1;
    }
};