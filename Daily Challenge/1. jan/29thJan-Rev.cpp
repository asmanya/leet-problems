#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    void push(int x) {
        stack_push.push(x);
    }

    void transferElements() {
        if (stack_pop.empty()) {
            while (!stack_push.empty()) {
                stack_pop.push(stack_push.top());
                stack_push.pop();
            }
        }
    }

    int pop() {
        transferElements();

        if (!stack_pop.empty()) {
            int frontElement = stack_pop.top();
            stack_pop.pop();
            return frontElement;
        }

        return -1; 
    }

    int peek() {
        transferElements();

        if (!stack_pop.empty()) {
            return stack_pop.top();
        }

        return -1;
    }

    bool empty() {
        return stack_push.empty() && stack_pop.empty();
    }

private:
    std::stack<int> stack_push;
    std::stack<int> stack_pop;
};