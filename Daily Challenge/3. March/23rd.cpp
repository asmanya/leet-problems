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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Find the middle of the list
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* second_half = reverse(slow->next);
        slow->next = nullptr;

        // Merge the two halves
        ListNode* first_half = head;
        while (second_half) {
            ListNode* temp1 = first_half->next;
            ListNode* temp2 = second_half->next;
            first_half->next = second_half;
            second_half->next = temp1;
            first_half = temp1;
            second_half = temp2;
        }
    }
};
