#include<iostream>
using namespace std;


// Definition of doubly linked list:
  
   struct Node {
        int value;
        Node *prev;
        Node *next;
        Node() : value(0), prev(nullptr), next(nullptr) {}
        Node(int val) : value(val), prev(nullptr), next(nullptr) {}
        Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
   };

Node * insertAtTail(Node *head, int k) {
    Node *t = new Node(k);
    if(head == nullptr)
    {
        head = t;
    }
    else{
        Node *p = head;
        while(p->next)
        {
            p = p->next;
        }

        p->next = t;
        t->prev = p;
    }
    return head;
}
