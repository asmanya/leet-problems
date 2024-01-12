#include<bits/stdc++.h>
using namespace std;

class disjointSet {
public:
    vector<int> size, parent;
    disjointSet(int n) {
        size.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u; 
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        disjointSet ds(n);
        int countExtra = 0;
        for(int i = 0; i < connections.size(); i++) {
                if(ds.findUPar(connections[i][0]) == ds.findUPar(connections[i][1])) {
                    countExtra++;
                } else {
                    ds.unionBySize(connections[i][0], connections[i][1]);
                }
            }

        int countComp = 0;
        for(int i = 0; i < n; i++) {
            if(ds.parent[i] == i) countComp++;
        }
        
        int ans = countComp - 1;
        if(countExtra >= ans) {
            return ans;
        }

        return -1;
    }
};