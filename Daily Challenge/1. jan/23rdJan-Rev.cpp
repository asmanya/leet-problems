#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(const vector<string>& arr) {
        int maxLength = 0;
        string current = "";
        backtrack(arr, 0, current, maxLength);
        return maxLength;
    }

private:

    bool hasUniqueCharacters(const string& s) {
        unordered_set<char> uniqueChars;
        for (char c : s) {
            if (uniqueChars.count(c) > 0) {
                return false;
            }
            uniqueChars.insert(c);
        }
        return true;
        }

    void backtrack(const vector<string>& arr, int index, string& current, int& maxLength) {

         if (hasUniqueCharacters(current)) {
            maxLength = max(maxLength, static_cast<int>(current.length()));
        }

        for (int i = index; i < arr.size(); ++i) {
            current += arr[i];
            backtrack(arr, i + 1, current, maxLength);
            current.resize(current.size() - arr[i].size()); 
        }
    }
};