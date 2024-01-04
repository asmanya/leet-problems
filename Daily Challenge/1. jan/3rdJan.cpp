#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> cams;
        
        for(int i = 0; i < bank.size(); i++) {
            int count = 0;
            for(auto it : bank[i]) {
                if(it == '1') {
                    count++;
                }
            }
            if(count > 0) {
                cams.push_back(count);
            }
        }

        int total = 0;
        for(int i = 1; i < cams.size(); i++) {
            total += cams[i] * cams[i-1];
        }
        return total;
    }
};