#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findChampion(vector<vector<int>> &grid)
    {
        vector<int> res;
        int sum = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum += grid[i][j];
            }
            res.push_back(sum);
            sum = 0;
        }
        int maxValue = INT_MIN;
        for(auto it = res.begin(); it != res.end(); it++){
            if(*it > maxValue){
                maxValue = *it;
            }
        }
        int i;
        for(i = 0; i< n; i++)
        {
            if(res[i] == maxValue){
                break;
            }
        }
        return i;
    }
};
