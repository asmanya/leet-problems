#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash;
        int sum = 0;
        int maxLength = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i] == 0 ? -1 : 1;
            if (sum == 0) {
                maxLength = i + 1;
            } else {
                if (hash.find(sum) != hash.end()) {
                    maxLength = max(maxLength, i - hash[sum]);
                } else {
                    hash[sum] = i;
                }
            }
        }

        return maxLength;
    }
};
