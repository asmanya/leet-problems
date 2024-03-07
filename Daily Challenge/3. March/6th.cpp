#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        
        ListNode* slow = head, *fast = head;

        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) return true;
        }

        return false;
    }
};