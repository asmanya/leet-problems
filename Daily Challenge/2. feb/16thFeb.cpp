#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        map<int, int> hashMap; 

        for(int i = 0; i < n; i++) {
            hashMap[arr[i]]++;
        }

        vector<pair<int, int>> hashVec;

        for(auto pair : hashMap) {
            hashVec.push_back({pair.second, pair.first});
        }

        sort(hashVec.begin(), hashVec.end());
        int count = hashVec.size(), ind = 0; 

        while(k > 0) {
            if(k >= hashVec[ind].first) {
                k -= hashVec[ind].first;
                ind++;
            }
            else {
                break;
            }
        }

        return hashVec.size() - ind;
    }
};