#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));

        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        map<int, int> dp;
        dp[0] = 0;

        for (const auto& job : jobs) {
            int val = job[2] + (--dp.upper_bound(job[0]))->second;

            if (val > dp.rbegin()->second) {
                dp[job[1]] = val;
            }
        }

        return dp.rbegin()->second;
    }
};