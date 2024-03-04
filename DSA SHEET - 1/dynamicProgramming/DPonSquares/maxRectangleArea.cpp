#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxA = 0, n = heights.size();

        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width;

                if(st.empty()) width = i;
                else width = i - st.top() - 1;

                maxA = max(maxA, height * width);
            }
            st.push(i);
        }

        return maxA;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
       int res = 0, n = matrix.size(), m = matrix[0].size();
       vector<int> height(m, 0);

       for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
               if(matrix[i][j] == '1') height[j]++;
               else height[j] = 0;
            }
            int area = largestRectangleArea(height);
            res = max(res, area);
       }

       return res;

    }
};