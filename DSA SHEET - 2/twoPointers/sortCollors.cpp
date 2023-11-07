#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), temp;
        for (int i = 0; i < n-1; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if(nums[i] > nums[j])
                {
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
    }
};

class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid = 0;

        // Dutch National Flag Algorithm
        while(mid <= high){
            switch(nums[mid]){
                case 0:
                    swap(nums[low++], nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
    }
};