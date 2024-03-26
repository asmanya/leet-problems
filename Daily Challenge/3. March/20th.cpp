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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *a1 = list1;

        for(int i = 0; i < a - 1; i++) {
            if(a1 && a1->next) {
                a1 = a1->next;
            }
            else {
                a1->next = list2;
                return list1;
            }
        }

        ListNode *a2 = a1;
        for(int i = 0; i <= b - a + 1; i++) {
            if(a2 && a2->next) {
                a2 = a2->next;
            }
        }

        ListNode *b1 = list2, *b2 = nullptr;
        while(b1) {
            b2 = b1;
            b1 = b1->next; 
        }

        b2->next = a2;
        a1->next = list2;

        return list1;
    }
};