#include<iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        bool sign = (dividend >= 0) == (divisor >= 0)? true : false;
        long long absDividend = abs(static_cast<long long>(dividend));
        long long absDivisor = abs(static_cast<long long>(divisor));

        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }

        while(absDividend - absDivisor >= 0) {
            int count = 0;
            while(absDividend - (absDivisor << 1 << count) >= 0) {
                count++;
            }
            result += 1 << count;
            absDividend -= absDivisor << count;
        }
        return sign? result: -result;
    }
};