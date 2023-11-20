#include <iostream>
using namespace std;

// TIME EXCEEDED ERROR IN SOME CASES
class Solution {
private:
    long long count(string &s) {
        int count = 0, same = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0' && s[i - 1] == '1') {
                swap(s[i], s[i - 1]);
                count++;
                if (same != 0) {
                    for (int j = same; j > 0; j--) {
                        i--;
                        swap(s[i], s[i - 1]);
                        count++;
                    }
                }
            }
            else if (s[i] == '1' && s[i - 1] == '1') {
                same++;
            }
        }
        return count;
    }

public:
    long long minimumSteps(string s) {
        return count(s);
    }
};
