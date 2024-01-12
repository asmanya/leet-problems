#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1 = 0, count2 = 0;
        for(int i = 0; i < s.size()/2; i++) {
            char first = s[i];
            char second = s[s.size()-1-i];
            if(first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u' ||
            first == 'A' || first == 'E' || first == 'I' || first == 'O' || first == 'U') {
                count1++;
            }
            if(second == 'a' || second == 'e' || second == 'i' || second == 'o' || second == 'u' ||
            second == 'A' || second == 'E' || second == 'I' || second == 'O' || second == 'U') {
                count2++;
            }
        }
        return count1 == count2;
    }
};