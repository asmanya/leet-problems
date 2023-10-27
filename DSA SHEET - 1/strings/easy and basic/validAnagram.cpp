#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> charCount;

        if( s.length() != t.length())
        {
            return false;
        }

        for(char &c : s)
        {
            charCount[c]++;
        }

        for(char &c : t)
        {
            if(charCount.find(c) != charCount.end() && charCount[c] > 0)
            {
                charCount[c]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};