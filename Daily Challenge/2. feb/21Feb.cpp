#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count1 = 1, count2 = 1;

        long long i = 1;
        while(left >= i) {
            i = i << 1;
            count1++;
        }

        i = 1;
        while(right >= i) {
            i = i << 1;
            count2++;
        }

        if(count1 < count2) return 0;

        long long ans = left;
        for(long long i = left; i <= right; i++) {
            ans = i & ans;
        }

        return (int)ans;
    }
};