#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        sort(matches.begin(), matches.end());
        map<int, int> lostMatches;
        vector<vector<int>> answer(2);

        for(auto pair : matches) {
            lostMatches[pair[1]]++;
        }

        for(auto pair : matches) {
            if((answer[0].empty() || answer[0].back() != pair[0]) && lostMatches.find(pair[0]) == lostMatches.end()) {
                answer[0].push_back(pair[0]);
            }
        }

        for(auto it: lostMatches){
            if(it.second == 1) {
                answer[1].push_back(it.first);
            }
        }
        
        return answer;
    }
};