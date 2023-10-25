#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;

            if (nums[mid] == target || nums[low] == target || nums[high] == target)
            {
                return true;
            }

            while (low < mid && nums[low] == nums[mid])
            {
                low++;
            }
            while (mid < high && nums[mid] == nums[high])
            {
                high--;
            }

            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && nums[mid] >= target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[high] >= target && nums[mid] <= target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};