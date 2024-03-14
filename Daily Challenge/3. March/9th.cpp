#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int first = nums1.size() - 1, second = nums2.size() - 1, res = -1;

        while(first >= 0 && second >= 0) {
            if(nums1[first] == nums2[second]) {
                res = nums1[first];
                first--;
            } else if(nums1[first] < nums2[second]) {
                second--;
            } else {
                first--;
            }
        }
        
        return res;
    }
};