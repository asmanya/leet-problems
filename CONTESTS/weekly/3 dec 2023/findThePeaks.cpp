#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        int i = 2, n = mountain.size();
        vector<int> res;
        while(i < n){
            if(mountain[i-1] > mountain[i-2] && mountain[i-1] > mountain[i]){
                res.push_back(i-1);
            }
            i++;
        }
        return res;
    }
};