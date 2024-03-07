#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int count1 = 0, res = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ')' && count1 == 0) {
                res++;
            } else if(s[i] == '(') {
                res++;
                count1++;
            } else if(s[i] == ')' && count1 != 0) {
                res--;
                count1--;
            }
        }

        return res;

    }
};