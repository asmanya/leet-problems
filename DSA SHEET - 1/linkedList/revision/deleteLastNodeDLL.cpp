#include <iostream>
using namespace std;

// Definition of doubly linked list:

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node() : data(0), prev(nullptr), next(nullptr) {}
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
};

Node *deleteLastNode(Node *head)
{
    Node *p = head;

    if (p->next == nullptr)
    {
        return NULL;
    }

    while (p->next)
    {
        p = p->next;
    }
    
    p->prev->next = nullptr;
    p->prev = nullptr;
    int x = p->data;
    delete (p);

    return head;
}
