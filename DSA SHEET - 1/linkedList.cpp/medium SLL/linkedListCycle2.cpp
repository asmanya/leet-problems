#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *p, *q, *r;
        p = q = r = head;
        if (!head || !head->next)
        {
            return nullptr;
        }
        while (p && p->next)
        {
            p = p->next->next;
            q = q->next;
            if (p == q)
            {
                break;
            }
        }

        if (p != q)
        {
            return nullptr;
        }

        while (p != r)
        {
            r = r->next;
            p = p->next;
        }
        return r;
    }
};