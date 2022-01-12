#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        Node *next;
        int data;

        Node(int data);
};

Node::Node(int data) {
    this->data = data;
    this->next = NULL;
};

class LinkedList {
    public:
        Node* head;

        void print();
        void push(int data);
        void reverse();
        LinkedList();
};

LinkedList::LinkedList() {
    head = NULL;
}

void LinkedList::print() {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void LinkedList::push(int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void LinkedList::reverse() {
    Node *current = head;
    Node *previous = NULL;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

int main() {

    LinkedList ll;

    ll.push(10);
    ll.push(20);
    ll.push(30);
    ll.push(40);
    ll.push(50);
    ll.push(60);

    cout << "Linked List -> ";
    ll.print();
    cout << endl;
    
    cout << "Reversing Linked List..." << endl;
    cout << "Linked List -> ";
    ll.reverse(); 
    ll.print();

    return 0;
}