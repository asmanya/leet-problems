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
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newHead = nullptr, *first = list1, *second = list2;

        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
 
        if(first->val <= second->val) {
            newHead = new ListNode(first->val);
            first = first->next;
        } else {
            newHead = new ListNode(second->val);
            second = second->next;
        }

        ListNode* prev = newHead;

        while(first && second) {
            ListNode* node = nullptr;
            
            if(first->val <= second->val) {
                node = new ListNode(first->val);
                first = first->next;
            } else {
                node = new ListNode(second->val);
                second = second->next;
            }
            prev->next = node;
            prev = node;
        } 

        if(!first) {
            ListNode* node = nullptr;
            while(second) {
                node = new ListNode(second->val);
                prev->next = node;
                prev = node;
                second = second->next;
            }
        }

        if(!second) {
            ListNode* node = nullptr;
            while(first) {
                node = new ListNode(first->val);
                prev->next = node;
                prev = node;
                first = first->next;
            }
        }

        return newHead;
    }
};