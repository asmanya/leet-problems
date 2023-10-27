#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int minSize, i= 0, j = 0, k = 0;
        vector<int> res(m+n, 0);

        while(i < m && j < n)
        {
            if(nums1[i] <= nums2[j])
            {
                res[k++] = nums1[i++];
            }
            else if(nums2[j] < nums1[i])
            {
                res[k++] = nums2[j++];
            }
        }

        while( i < m)
        {
            res[k++] = nums1[i++];
        }
        while( j < n)
        {
            res[k++] = nums2[j++];
        }

        for(int i = 0; i < (m+n) ; i++)
        {
            nums1[i] = res[i];
        }
    }
};