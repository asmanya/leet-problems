#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        set<int> rowSet, colSet;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(matrix[row][col] == 0) {
                    rowSet.insert(row);
                    colSet.insert(col);
                }
            }
        }

        for(const auto& row : rowSet) {
            for(int i = 0; i < m; i++) {
                matrix[row][i] = 0;
            }
        }

        for(const auto& col : colSet) {
            for(int i = 0; i < n; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};