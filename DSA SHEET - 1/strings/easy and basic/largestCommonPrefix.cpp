#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        if(strs.empty())
        {
            return res;
        }

        int minLength = INT_MAX;
        for(string &s : strs)
        {
            minLength = min(minLength, static_cast<int>(s.length()));
        }

        for(int i = 0; i < minLength; i++)
        {
            char temp = strs[0].at(i);
            for(int j = 1; j < strs.size(); j++ )
            {
                char temp1 = strs[j].at(i);
                if(temp != temp1)
                {
                    return res;
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};