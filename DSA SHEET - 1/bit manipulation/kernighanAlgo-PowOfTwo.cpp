#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        // Kernighan's Algorithm

        int count = 0;
        if(n < 0) {
            return false;
        }
        while(n) {
            count++;
            n = n & (n-1);
        }
        if(count == 1) {
            return true;
        }
        return false;
    }
};