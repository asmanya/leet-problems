#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> hash(nums.size() + 1, 0);

        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }

        vector<int> res(2, 0);
        for(int i = 0; i < nums.size()+1; i++) {
            if(hash[i] == 2) {
                res[0] = i;
            }
            if(hash[i] == 0) {
                res[1] = i;
            }
        }
        return res;
    }
};