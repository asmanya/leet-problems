#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows, cols;
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for(auto &i : rows)
        {
            for(int j = 0; j < m; j++)
            {
                matrix[i][j] = 0;
            }
        }
        for(auto &j : cols)
        {
            for(int i = 0; i < n; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }
};