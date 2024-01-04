#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> umap;

        for(int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
        }

        for(auto it : umap) {
            if(it.second % 3 == 0) {
                int temp = it.second / 3;
                res += temp;
            }
            else if(it.second == 1) {
                return -1;
            }
            else {
                while(it.second > 4) {
                    it.second -= 3;
                    res++;
                }
                if(it.second == 4) {
                    res += 2;
                } else if( it.second == 3 || it.second == 2) {
                    res++;
                }
                else if( it.second == 1) {
                    return -1;
                }
            }
        }
        return res;
    }
};