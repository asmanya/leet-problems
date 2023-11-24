#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        vector<int> left(n), right(n);

        // Left Stack
        stack<int> lStack;
        lStack.push(0);

        left[0] = 1;

        for(int i = 1; i < n; i++) {
            while(!lStack.empty() && arr[i] < arr[lStack.top()]) {
                lStack.pop();
            }
            left[i] = lStack.empty() ? i + 1 : i - lStack.top();

            lStack.push(i);
        }

        // Right Stack
        stack<int> rStack;
        rStack.push(n-1);

        right[n-1] = 1;

        for(int i = n - 1; i >= 0; i--) {
            while(!rStack.empty() && arr[i] <= arr[rStack.top()]) {
                rStack.pop();
            }
            right[i] = rStack.empty() ? n - i : rStack.top() - i;
            rStack.push(i);
        }

        // calculating res
        long long res = 0;
        for(int i = 0; i < n; i ++) {
            long long prod = left[i] * right[i];
            long long net = (arr[i] * prod) % MOD;
            res = (res + net) % MOD;
        }

        return res;
    }
};