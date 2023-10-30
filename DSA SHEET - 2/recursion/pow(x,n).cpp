#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1) return 1;
        if(x == 0) return 0;

        if (n == INT_MIN) {
            x = x * x;
            n = n / 2;
        }

        if(n > 0) {
            if(n % 2 == 0) {
                n = n /2;
                double result = myPow(x, n);
                return result * result;
            }
            else if(n % 2 != 0) {
                return x * myPow(x , n-1);
            }
        }
        else if(n < 0) {
            n = -n;
            double result = myPow(x, n);
            return 1/result;
        }
        
        return 1;
    }
};