#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

struct LinkedList {
    Node *head;

    LinkedList() {
        head = NULL;
    }

    void push(int data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void print() {
        Node *current = head;

        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
    }

    void reverse() {
        Node *current = head;
        Node *next = NULL;
        Node *previous = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }
};

int main() {

    LinkedList ll = LinkedList();

    ll.push(10);
    ll.push(20);
    ll.push(30);
    ll.push(40);
    ll.push(50);

    cout << "Linked List -> ";
    ll.print();
    cout << endl;

    cout << "Reversing Linked List..." << endl;
    ll.reverse();
    cout << "Linked List -> ";
    ll.print();
    cout << endl;
    
    return 0;
}