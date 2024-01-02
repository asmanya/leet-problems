#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    int indegree[nodes];
    for(int i = 0; i < nodes; i++) {
        for(auto it: graph[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < nodes; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it: graph[node]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    return topo;
}
