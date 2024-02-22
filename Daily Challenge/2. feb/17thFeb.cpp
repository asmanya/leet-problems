#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> max_heap;

        int i = 0;
        for(i ; i < heights.size() -1 ; i++) {
            int diff = heights[i+1] - heights[i];

            if(diff <= 0) {
                continue;
            }
            else {
                if(diff <= bricks) {
                    bricks -= diff;
                    max_heap.push(diff);
                }
                else if(ladders > 0) {
                    if(max_heap.size()) {
                        int currMaxBricks = max_heap.top();
                        if(currMaxBricks >= diff) {
                            bricks += currMaxBricks;
                            max_heap.pop();
                            max_heap.push(diff);
                            bricks -= diff;
                        }
                    }
                    ladders--;
                }
                else {
                    return i;
                }
            }
        }
        return i;
    }
};