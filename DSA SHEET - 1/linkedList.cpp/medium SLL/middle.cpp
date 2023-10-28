#include <iostream>
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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *p, *q, *temp;
        p = q = head;
        while (q && q->next)
        {
            q = q->next->next;
            p = p->next;
        }
        return p;
    }
};