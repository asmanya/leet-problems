#include<bits/stdc++.h>
using namespace std;

//  LPS 

class Solution {
private:
    void func(vector<int>& lps, string a) {
        int i = 0, j = 1;

        while(j < a.length()) {
            if(a[i] == a[j]) {
                i++;
                lps[j] = i;
                j++;
            } else {
                if(i == 0) {
                    j++;
                } else {
                    i = lps[i-1];
                }
            }
        }
    }
public:
    string longestPrefix(string s) {
        vector<int> lps(s.length(), 0);
        func(lps, s);

        int i = lps[s.length()- 1];
        string res = "";

        for(int k = 0; k < i; k++) {
            res += s[k];
        }

        return res;
    }
};