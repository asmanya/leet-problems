#include<iostream>
using namespace std;

class Solution {
public:
    void swapNumber(int &a, int &b) {
	    a = a ^ b;
	    b = a ^ b;
	    a = a ^ b;
    }
};