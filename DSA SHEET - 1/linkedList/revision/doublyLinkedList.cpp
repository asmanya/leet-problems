#include<iostream>
#include<vector>
using namespace std;

// Definition for doubly-linked list.
   class Node
   {
   public:
      int data;
      Node *next, *prev;
      Node() : data(0), next(nullptr), prev(nullptr) {}
      Node(int x) : data(x), next(nullptr), prev(nullptr) {}
      Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
   };

Node* constructDLL(vector<int>& arr) {
    if(arr.size() == 0)
    {
        return nullptr;
    }

    Node *head = new Node(arr[0]), *last = head, *t;

    for(int i = 1; i < arr.size(); i++)
    {
        t = new Node(arr[i]);
        last->next = t;
        t->prev = last;
        last = t;
    }
    return head;
}
