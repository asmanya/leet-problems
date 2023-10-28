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
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode *p = head, *q = head, *r = nullptr;
        if (!head->next)
        {
            return nullptr;
        }

        while (q && q->next)
        {
            r = p;
            p = p->next;
            q = q->next->next;
        }
        r->next = p->next;
        delete (p);
        return head;
    }
};