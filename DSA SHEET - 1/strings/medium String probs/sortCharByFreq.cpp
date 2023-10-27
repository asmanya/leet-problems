#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> charCount;
        string str = "";

        // inserted values in ordered map
        for(char &c : s)
        {
            charCount[c]++;
        }

        // inserted order map values into vector
        vector<pair<char,int>> vec(charCount.begin(), charCount.end());

        // sorting vector based on values of value
        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b)
        {
            return a.second > b.second;
        });

        // creating string based on number of occurances of character
        for(auto &pair : vec)
        {
            while( pair.second > 0)
            {
                str += pair.first;
                pair.second--;
            }
        }

        // returning string
        return str;
    }
};