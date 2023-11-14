#include<iostream>
using namespace std;

class Solution {
public:
    int setBits(int N){
        if(N == 0) {
            return 1;
        }
        int mask = 1;
        while(N & mask) {
            mask << 1;
        }
    return N | mask;
}
};