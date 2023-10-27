#include <iostream>
using namespace std;

// Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next, *prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

Node *reverseDLL(Node *head)
{
    Node *p = head, *q = nullptr, *r = nullptr;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
        q->prev = p;
    }
    head = q;
    return head;
}
