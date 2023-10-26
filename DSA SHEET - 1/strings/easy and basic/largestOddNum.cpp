#include<iostream>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        string res = "";
        int i = num.length() - 1;
        while(i > -1 && num[i] % 2 == 0)
        {
            i--;
        }
        for(int j = 0; j <= i; j++)
        {
            res += num[j];
        }
        return res;
    }
};