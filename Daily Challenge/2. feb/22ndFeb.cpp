#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>> hash(n + 1, {0,0}); // trusts, trusted By
        
        for(auto vec: trust) {
            hash[vec[0]].first++;
            hash[vec[1]].second++;
        }

        for(int i = 1; i <= n; i++){
            if(hash[i].first == 0 && hash[i].second == n-1) {
                return i;
            }
        }

        return -1;
    }
};