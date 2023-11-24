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
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *p = head, *q = nullptr, *r = nullptr, *last = nullptr;
        if (!head)
        {
            return head;
        }

        while (p && p->next)
        {
            if (!q)
            {
                r = p->next;
            }
            else
            {
                ;
                q->next = p->next;
            }
            q = p->next;
            last = p;
            p->next = p->next->next;
            p = p->next;
        }

        if (q)
        {
            q->next = nullptr;
        }

        if (!p)
        {
            p = r;
            last->next = p;
        }
        else
        {
            p->next = r;
        }

        return head;
    }
};