#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }

        unordered_map<char, int> target_counts;
        int required_chars = 0;
        for (char c : t) {
            target_counts[c]++;
            required_chars++;
        }

        int formed_chars = 0;
        unordered_map<char, int> window_counts;

        int left = 0, right = 0, min_len = INT_MAX, start_idx = 0;

        while (right < s.length()) {
            char current_char = s[right];
            window_counts[current_char]++;

            if (target_counts.find(current_char) != target_counts.end() &&
                window_counts[current_char] <= target_counts[current_char]) {
                formed_chars++;
            }

            while (formed_chars == required_chars) {
                int window_size = right - left + 1;
                if (window_size < min_len) {
                    min_len = window_size;
                    start_idx = left;
                }

                char left_char = s[left]; 
                window_counts[left_char]--;

                if (target_counts.find(left_char) != target_counts.end() &&
                    window_counts[left_char] < target_counts[left_char]) {
                    formed_chars--;
                }

                left++;
            }

            right++;
        }

        return (min_len == INT_MAX) ? "" : s.substr(start_idx, min_len);
    }
};