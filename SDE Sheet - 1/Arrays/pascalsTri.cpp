#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});

        for(int i = 1; i < numRows; i++) {
            vector<int> temp(i+1, 1);

            int size = res.back().size();

            for(int j = 1; j < size - 1; j++) {
                temp[j] = res.back()[j] + res.back()[j-1];
            }

            res.push_back(temp);
        }

        return res;
    }
};
