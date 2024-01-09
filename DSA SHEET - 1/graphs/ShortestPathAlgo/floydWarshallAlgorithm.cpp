#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void floydWarshall(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // if a node is not reachable from any other node, its denoted by -1, so changing it to 1e9
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == -1) {
                    matrix[i][j] = 1e9;
                }
                if( i== j) matrix[i][j] = 0;
            }
        }

        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    matrix[i][j] = min(matrix[i][j],
                    matrix[i][via] + matrix[via][j]);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(matrix[i][i] < 0) {
                // matrix have a negative cycle
            }
        }


        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1e9) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};