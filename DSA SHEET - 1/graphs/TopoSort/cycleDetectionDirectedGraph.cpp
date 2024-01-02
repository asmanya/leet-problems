#include<bits/stdc++.h>
using namespace std;

bool dfsCheck(int node, vector<vector<int>>& edges, vector<int> &vis, vector<int> &pathVis) {
  vis[node] = 1;
  pathVis[node] = 1;

  for(auto it: edges[node]) {
    if(!vis[node]) {
      if(dfsCheck(it, edges, vis, pathVis) == true) return true;
    } else if(pathVis[it]) {
      return true;
    }
  }

  pathVis[node] = 0;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < vector < int >> & edges) {
  vector<int>vis (n, 0);
  vector<int>pathVis (n, 0);

  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      if(dfsCheck(i, edges, vis, pathVis) == true) return true;
    }
  }
  return false;
}