#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
void helper(int index, vector<int>& ds, int n, int limit, int& count) {
        if (index == 3) {
            if (n == 0) {
                count++;
            }
            return;
        }
        for (int i = 0; i <= min(n, limit); ++i) {
            ds[index] = i;
            helper(index + 1, ds, n - i, limit, count);
        }
    }

public:
    int distributeCandies(int n, int limit) {
        int count = 0;
        vector<int> ds(3, 0);
        helper(0, ds, n, limit, count);
        return count;
    }
};

int main() {
    Solution sol;
    int result = sol.distributeCandies(3, 3);
    cout << result;
    return 0;
}
