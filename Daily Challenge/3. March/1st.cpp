#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count1= 0, count0 = 0;
        for(auto it: s) {
            if(it == '1') count1++;
            else count0++;
        }

        string res;
        for(int i = 0; i < count1-1; i++) {
            res += '1';
        }
        for(int i = 0; i < count0; i++) {
            res += '0';
        }

        res += '1';
        return res;
    }
};