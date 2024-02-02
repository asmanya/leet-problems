#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        int ls = to_string(low).length();
        int hs = to_string(high).length();

        vector<int> res;
        for(int i = ls; i <= hs; ++i) {
            for(int j = 0; j < 10 - i; ++j) {
                int num = stoi(digits.substr(j, i));
                if(num >= low && num <= high) res.push_back(num);
            }
        }
        return res;
    }
};