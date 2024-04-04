#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> umap;
        set<char> hash;

        for(int i = 0; i < s.size(); i++) {
            if(umap.find(s[i]) == umap.end()) {
                if(hash.find(t[i]) == hash.end()) {
                    umap[s[i]] = t[i];
                    hash.insert(t[i]);
                }
                else 
                    return false;
            }      
            else
                if(umap[s[i]] == t[i])
                    continue;
                else
                    return false;
        }

        return true;
    }
};