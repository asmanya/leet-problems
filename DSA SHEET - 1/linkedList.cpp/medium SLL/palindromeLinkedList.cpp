#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *p = head;
        vector<int> nums;

        while (p)
        {
            nums.push_back(p->val);
            p = p->next;
        }

        for (int i = 0, j = nums.size() - 1; i < j; i++, j--)
        {
            if (nums[i] == nums[j])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};