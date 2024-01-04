#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfsCheck(int node, vector<vector<int>> &edges, vector<int> &vis, vector<int> &pathVis, vector<int> &check)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for (auto it : edges[node])
        {
            if (!vis[it])
            {
                if (dfsCheck(it, edges, vis, pathVis, check) == true)
                    return true;
            }
            else if (pathVis[it])
            {
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> vis(graph.size(), 0);
        vector<int> pathVis(graph.size(), 0);
        vector<int> check(graph.size(), 0);
        vector<int> res;

        for (int i = 0; i < graph.size(); i++)
        {
            if (!vis[i])
            {
                dfsCheck(i, graph, vis, pathVis, check);
            }
        }

        for (int i = 0; i < graph.size(); i++)
        {
            if (check[i] == 1)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};