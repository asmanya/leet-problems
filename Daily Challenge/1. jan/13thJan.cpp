#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        if (s.length() != t.length()) {
            return -1;
        }

        unordered_map<char, int> frequencyS, frequencyT;

        for (char ch : s) {
            frequencyS[ch]++;
        }

        for (char ch : t) {
            frequencyT[ch]++;
        }

        int steps = 0;
        for (const auto& entry : frequencyS) {
            char ch = entry.first;
            int countS = entry.second;
            int countT = frequencyT[ch];

            steps += max(0, countS - countT);

        }

        return steps;
    }
};