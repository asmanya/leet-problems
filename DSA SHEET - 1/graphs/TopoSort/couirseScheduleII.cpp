#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfsCheck( int node, vector<int> adjList[], vector<int> &vis, vector<int> &pathVis, stack<int> &st) {
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adjList[node]) {
            if(!vis[it]) {
                if( dfsCheck( it, adjList, vis, pathVis, st) == true) return true;
            }
            else if (pathVis[it]) {
                return true;
            }
        }

        st.push(node);
        pathVis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites, stack<int> &st) {

        vector<int> adjList[numCourses];

        for(auto it : prerequisites) {
            adjList[it[1]].push_back(it[0]);
        }

        vector<int>vis (numCourses, 0);
        vector<int>pathVis (numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if( dfsCheck( i, adjList, vis, pathVis, st) == true ) return false;
            }
        }

        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        stack<int> st;

        if(canFinish(numCourses, prerequisites, st) == false) {
            return res;
        }
        
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};