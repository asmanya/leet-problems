#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSum = 0, winSum = 0, mark = 0, maxSum = 0, n = cardPoints.size();

        for(auto x : cardPoints) {
            totalSum += x;
        }
        while(mark < n-k) {
            winSum += cardPoints[mark];
            mark++;
        }
        maxSum = max(maxSum, totalSum - winSum);
        for(int i = mark; i < n; i++) {
            winSum += cardPoints[i] - cardPoints[i-(n-k)];
            maxSum = max(maxSum, totalSum - winSum);
        }
        return maxSum;
    }
};