#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>> sortedVec(strs.size());
        for(int i = 0; i < strs.size(); i++) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            sortedVec[i] = {sorted, i};
        }

        sort(sortedVec.begin(), sortedVec.end());

        vector<vector<string>> res;
        int count = 0;

        res.push_back({strs[sortedVec[0].second]});

        for (int i = 1; i < sortedVec.size(); i++) {
            if (sortedVec[i].first == sortedVec[i - 1].first) {
                res[count].push_back(strs[sortedVec[i].second]);
            } else {
                res.push_back({strs[sortedVec[i].second]});
                count++;
            }
        }

        return res;
    }
};