#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int prefixSum = 0;
        unordered_map<int, int> sumFreq;
        
        sumFreq[0] = 1; 
        
        for (int num : nums) {
            prefixSum += num;
            
            if (sumFreq.find(prefixSum - k) != sumFreq.end()) {
                count += sumFreq[prefixSum - k];
            }
            
            sumFreq[prefixSum]++;
        }
        
        return count;   
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int result = 0;

        for (int i = 0; i < rows; ++i) {
            vector<int> rowSum(cols, 0);

            for (int j = i; j < rows; ++j) {
                for (int k = 0; k < cols; ++k) {
                    rowSum[k] += matrix[j][k];
                }

                result += subarraySum(rowSum, target);
            }
        }

        return result;
    }
};