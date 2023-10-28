#include <iostream>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p = l1, *q = l2, *t, *last, *head = nullptr;
        int sum = 0, rem = 0;

        while (p || q)
        {
            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            sum = x + y + rem;

            rem = sum / 10;
            if (!head)
            {
                head = new ListNode(sum % 10);
                last = head;
                p = p->next;
                q = q->next;
            }
            else
            {
                t = new ListNode(sum % 10);
                if (p != nullptr)
                {
                    p = p->next;
                }
                if (q != nullptr)
                {
                    q = q->next;
                }
                last->next = t;
                last = t;
            }
        }

        if (rem)
        {
            t = new ListNode(rem);
            last->next = t;
            last = t;
        }

        return head;
    }
};