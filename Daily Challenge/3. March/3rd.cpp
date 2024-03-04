#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // lets create a dummy node before the head node of the list
        ListNode dummy(0);

        // now we set the value of dummmy's next to head to join dummmy to list
        dummy.next = head;
    
        // we will create two more node pointers to traverse the list
        ListNode* ahead = &dummy, * prev = &dummy;

        // this loop sets ahead pointer n steps ahead of prev, and if there are less than n elements
        // origianl loop can be returned as there will be no nth node from end in that case
        for(int i = 0; i < n; i++) {
            if(ahead) 
                ahead = ahead->next;
            else 
                return head;
        }

        // now the gap between ahead and prev is n nodes, which means if ahead reaches the end,
        // the prev will reach n nodes behind ahead, which is itself n+1 (from last) node here in this case
        while(ahead && ahead->next) {
            ahead = ahead->next;
            prev = prev->next;
        }

        // so we set the value of nth node from last into a temp node, to use it and then delete it
        ListNode* temp = prev->next;

        // now here we set the next value of n+1 node (from last) to n-1 (from last), therefore removing n node from list
        prev->next = temp->next;

        // delete the value of the temp node, thus Nth node is removed from the back
        delete(temp);

        // return the head of the list
        return dummy.next;
    }
};