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
    void reverse(ListNode*& head) {
        ListNode* temp = head;  
        ListNode* prev = nullptr;  
        
        while(temp != nullptr) {  
            ListNode* front = temp->next;  
            temp->next = prev;  
            prev = temp;  
            temp = front; 
        }
    }

    ListNode* findNode(ListNode* temp, int k) {
        k -= 1;

        while(temp != nullptr && k > 0) {
            k--;
            temp = temp->next;
        }

        return temp;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode;
        ListNode* prevNode = nullptr; 

        while (temp != nullptr) {

            ListNode* kNode = findNode(temp, k);
            if (kNode == nullptr) {
                if (prevNode) prevNode->next = temp;
                break;
            }

            nextNode = kNode->next;
            kNode->next = nullptr;
            reverse(temp);

            if (temp == head)
                head = kNode;
            else
                prevNode->next = kNode;

            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};