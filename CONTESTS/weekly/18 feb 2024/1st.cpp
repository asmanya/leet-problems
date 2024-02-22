#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), count = 0;
        for(int i = 0; i < n-1; i++) {
            for(int j = i + 1; j < n; j++) {
                int size1 = words[i].size(), size2 = words[j].size();
                if(size1 > size2) continue;
                
                string str1 = words[j].substr(0, size1), str2 = words[j].substr(size2 - size1, size1);
                
                if(words[i] == str1 && words[i] == str2) count++;
            }
        }
        
        return count;
    }
};