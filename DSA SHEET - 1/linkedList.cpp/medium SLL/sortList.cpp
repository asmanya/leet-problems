#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//  Definition for singly-linked list.
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
    ListNode *sortList(ListNode *head)
    {
        ListNode *p = head;
        vector<int> values;
        while (p)
        {
            values.push_back(p->val);
            p = p->next;
        }
        sort(values.begin(), values.end());

        p = head;
        int i = 0;
        while (p)
        {
            p->val = values[i];
            p = p->next;
            i++;
        }
        return head;
    }
};
