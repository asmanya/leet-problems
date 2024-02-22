#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int m = meetings.size();

        // keeps a track of how many meets have happened in rooms
        vector<int> room_meeting_count(n, 0);

        // tells us about the room with loweest index that is available
        priority_queue<int, vector<int>, greater<int>> available;

        // tells us about the index of the room where the meet will end at the earliest
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
            greater<pair<long long, int>>> busy;

        // all rooms are available at the starting
        for(int i = 0; i < n; ++i) {
            available.push(i);
        }

        // checking for all the meetings
        for(const auto& meeting: meetings) {
            int start = meeting[0], end = meeting[1];

            // if there is any room that can be made available before new meet, making it available
            while(busy.size() > 0 && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            // if there is any room available
            if(available.size() > 0) {

                // creating a meet in that room
                int top = available.top();
                room_meeting_count[top]++;
                available.pop();

                // making the room busy again with the meeting's ending detail
                busy.push({end, top});
                continue;
            }

            // in case there are no rooms available for the current meet - we wait for the meet that end at earliest
            auto top = busy.top();
            int index = top.second;
            busy.pop();
            room_meeting_count[index]++;

            // previous meet end, so pushing details of the current meet into it with updated ending time 
            busy.push({top.first + end - start, index});
        }

        // returing the lowest ind room with highest number of meets
        return max_element(room_meeting_count.begin(), room_meeting_count.end())
             - room_meeting_count.begin();
    }
};


// testcases : 