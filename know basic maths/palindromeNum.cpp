#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        long rev = 0, rem;
        int temp = x;
        while(x > 0)
        {
            rem = x % 10;
            x = x /10;
            if(x > INT_MAX || x < INT_MIN){
                return false;
            }
            rev = rev*10 + rem;
        }
        if(int(rev) == temp){
            return true;
        }
    return false;
    }
};

int main()
{
    
    return 0;
}