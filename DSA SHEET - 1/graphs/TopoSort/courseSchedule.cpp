#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfsCheck( int node, vector<int> adjList[], vector<int> &vis, vector<int> &pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adjList[node]) {
            if(!vis[it]) {
                if( dfsCheck( it, adjList, vis, pathVis) == true) return true;
            }
            else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adjList[numCourses];

        for(auto it : prerequisites) {
            adjList[it[1]].push_back(it[0]);
        }

        vector<int>vis (numCourses, 0);
        vector<int>pathVis (numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if( dfsCheck( i, adjList, vis, pathVis ) == true ) return false;
            }
        }

        return true;
    }
};