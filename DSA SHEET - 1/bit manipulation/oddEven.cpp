#include<iostream>
using namespace std;

class Solution {
    string oddEven(int N){
        if(N & (1<<0)) {
            return "odd";
        }
        return "even";
    }
};