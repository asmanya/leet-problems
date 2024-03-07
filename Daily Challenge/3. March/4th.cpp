#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0;

        int n = tokens.size(), left = 0, right = n-1;

        if(!tokens.size()) return 0;

        while(left < right) {
            if(score >=  1 && power < tokens[left]) {
                score--;
                power += tokens[right];
                right--;
            }
            else if(power >= tokens[left]) {
                score++;
                power -= tokens[left];
                left++;
            }
            else if(power < tokens[left] && score < 1) break;
        }

        if(power >= tokens[left]) score++;

        return score;
    }
};