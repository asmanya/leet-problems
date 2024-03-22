#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* cur = head, *prev = nullptr, *n = nullptr;

        while(cur) {
            n = cur->next;
            cur->next = prev;
            prev = cur;
            cur = n;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {

        // this code runs in O(n) time complexity and O(1) space compplexity.
        // it alters the original data.

        if(head == nullptr || head->next == nullptr)
            return true;
        
        ListNode* slow = head, *fast = head;
        while(fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* t = reverse(slow->next);
        slow->next = nullptr;
        ListNode* c = head;

        while(t) {
            if(c->val != t->val)
                return false;
            c = c->next;
            t = t->next;
        }

        return true;
    }
};
