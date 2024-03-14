#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> mp;
        int res;

        for(const auto& num: nums) {
            mp[num]++;
            if(mp[num] == 2) {
                res = num;
                break;
            }
        }

        return res;
    }
};