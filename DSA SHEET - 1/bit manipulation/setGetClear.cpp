#include<iostream>
#include<vector>
using namespace std;

class Solution
{
private:
    int getBit(int num, int pos) {
        return (num & (1 << pos - 1)) != 0;
    }
    int setBit(int num, int pos) {
        return (num | (1 << pos - 1));
    }
    int clearBit(int num, int pos) {
        int mask = ~(1 << pos - 1);
        return (num & mask);
    }
public:
    vector<int> bitManipulation(int num, int i) {
        vector<int> res;
        res.push_back(getBit(num, i));
        res.push_back(setBit(num, i));
        res.push_back(clearBit(num, i));
        return res;
    }
};