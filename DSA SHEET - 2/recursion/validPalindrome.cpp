#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
public:
    bool isPalindrome(string s) {
        vector<char> res;
        for(char ch : s){
            int ASCIIValue = static_cast<int>(ch);
            if((ASCIIValue >= 97 && ASCIIValue <= 122) || (ASCIIValue >= 48 && ASCIIValue <= 57) ){
                res.push_back(ch);
            }
            else if(ASCIIValue >= 65 && ASCIIValue <= 90){
                ASCIIValue += 32;
                char newCh = static_cast<char>(ASCIIValue);
                res.push_back(newCh);
            }
            else{
                continue;
            }
        }
        int len = res.size();
        for(int i =0, j = len - 1; i < j; i++, j--){
            if(res[i] == res[j]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};