#include<bits/stdc++.h>
using namespace std;

class disjointSet {
public:
    vector<int> parent, size;
    disjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_v] > size[ulp_u]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
private:
    bool isValid(int row, int col, int n) {
        return row < n && row >= 0 && col < n && col >= 0; 
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjointSet ds(n * n);

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 0) continue;
                
                int dir[4][2] = {{0,-1}, {-1, 0}, {0,1}, {1, 0}};
                for(int d = 0; d < 4; d++) {
                    int newRow = row + dir[d][0];
                    int newCol = col + dir[d][1];

                    if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                        int node = row * n + col;
                        int adjNode = newRow * n + newCol;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        int mx = 0;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) continue; 

                set<int> components;
                int dir[4][2] = {{0,-1}, {-1, 0}, {0,1}, {1, 0}};
                for(int d = 0; d < 4; d++) {
                    int newRow = row + dir[d][0];
                    int newCol = col + dir[d][1];

                    if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                        components.insert(ds.findUPar(newRow * n + newCol));
                    }
                }

                int sizeTotal = 0;
                for(auto it : components) {
                    sizeTotal += ds.size[it];
                }

                mx = max(mx, sizeTotal + 1);
            }
        }

        for(int i = 0; i < n * n; i++) {
            mx = max(mx, ds.size[ds.findUPar(i)]);
        }

        return mx;

    }
};