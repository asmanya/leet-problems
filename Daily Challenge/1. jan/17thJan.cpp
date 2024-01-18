#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int, int> hash;
        for(auto it : arr) {
            hash[it]++;
        }

        unordered_map <int, int> check; 
        for(auto pair: hash) {
            check[pair.second]++;
            if(check[pair.second] > 1) {
                return false;
            }
        }
        return true;
    }
};