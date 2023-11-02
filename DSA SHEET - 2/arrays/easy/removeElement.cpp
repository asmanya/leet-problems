#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int low = 0, high = nums.size() - 1;
        if(nums.empty()){
            return 0;
        }

        while(low < high){
            if(nums[high] == val){
             // nums.pop_back();
                high--;
            } 
            else {
                if(nums[low] != val){
                    low++;
                }
                else {
                    swap(nums[low], nums[high]);
                    low++;
                }
            }
        }
        if(nums[high] == val){
            return low;
        }
        return low + 1;
    }
};