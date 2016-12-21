//
// Created by SunRenchen on 16-12-20.
//

#ifndef APP_STACK_H
#define APP_STACK_H

// Uses doubly linked list for implementing stack
// O(1) for all operations.

// If using array implmentation. The best can be constant amortized time.
// we need to enlarge and shrink accodingly
class Stack {
public:
    Stack();
    void pop();
    int top();
    void push(int val);
    int size();
    bool empty();

private:
    struct Node
    {
        Node():m_value(0),m_pre(nullptr), m_next(nullptr) {}
        Node(int val): m_value(val), m_pre(nullptr), m_next(nullptr) {}
        int m_value;
        Node* m_pre;
        Node* m_next;
    };
    Node* m_head;
    Node* m_tail;
    int m_size;
};


#endif //APP_STACK_H
