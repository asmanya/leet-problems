#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long rev = 0, rem;
        while(x != 0)
        {
            rem = x % 10;
            x = x / 10;
            rev = (rev * 10) + rem;
            if (rev > INT_MAX || rev < INT_MIN) {
                return 0;
             }
        }
        return int(rev);
    }
};
