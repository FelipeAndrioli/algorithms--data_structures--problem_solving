#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
    The methods could have been transformed to behave like a handling library, getting the
    stack as a parameter and then realizing the actions
*/

class Node {

    public:
        int data;
        Node* next;
};

Node* newNode(int value) {
    Node* node = new Node();
    node->data = value;
    node->next = NULL;

    return node;
}

class Stack {

    public:
        Node* root;      

    public:
        Stack();
        void push(int value);
        bool pop();
        bool isEmpty();
        int peek();
};

Stack::Stack() {
    root = NULL;
}

bool Stack::isEmpty() {
    return !root;
}

int Stack::peek() {

    if (isEmpty()) {
        return INT_MIN;
    }

    return root->data;
}

void Stack::push(int value) {
    Node* node = newNode(value);
    node->next = root;
    root = node;
}

bool Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return false;
    }

    root = root->next;
    return true;
}

int main() {

    Stack *stack = new Stack();

    stack->push(10);
    cout << "Current value on peek: " << stack->peek() << endl;
    stack->push(20);
    cout << "Current value on peek: " << stack->peek() << endl;
    stack->push(30);
    cout << "Current value on peek: " << stack->peek() << endl;
    stack->push(40);
    cout << "Current value on peek: " << stack->peek() << endl;
    stack->push(50);
    cout << "Current value on peek: " << stack->peek() << endl;

    cout << endl;

    while (!stack->isEmpty()) {
        cout << stack->peek() << endl;
        stack->pop();
    }

    stack->pop();

    return 0;
}