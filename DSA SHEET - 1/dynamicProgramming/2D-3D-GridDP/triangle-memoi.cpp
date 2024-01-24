#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int total(int ind, int last, vector<vector<int>>& triangle, vector<vector<int>>& memo) {
        if (ind == triangle.size()-1) {
            return triangle[ind][last];
        }

        if(memo[ind][last] != -1) return memo[ind][last];

        int first = triangle[ind][last] + total(ind + 1, last, triangle, memo);
        int second = triangle[ind][last] + total(ind + 1, last + 1, triangle, memo);

        return memo[ind][last] = min(first, second);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int minTot = INT_MAX, n = triangle.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));

        return total(0, 0, triangle, memo);
    }
};
