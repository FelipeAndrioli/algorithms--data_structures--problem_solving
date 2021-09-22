#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
		int data;
		Node* next;
};

Node* newNode(int data) {
	Node* node = new Node();
	node -> data = data;
	node -> next = NULL;

	return node;
}

int isEmpty(Node* root) {
	return !root;
}

void push(Node** root, int value) {
	Node* node = newNode(value);
	node -> next = *root;
	*root = node;

	cout << value << " pushed to stack" << endl;
}

int pop(Node** root) {
	if (isEmpty(*root)) {
		return INT_MIN;
	}

	Node* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

int peek(Node* root) {
	if (isEmpty(root)) {
		return INT_MIN;
	}

	return root->data;
}

int main() {

	Node* root = NULL;

	push(&root, 10);
	push(&root, 20);
	push(&root, 30);
	push(&root, 40);
	push(&root, 50);
	push(&root, 60);

	cout << pop(&root) << " popped from the stack" << endl;
	cout << "Top elements is " << peek(root) << endl;

	cout << "Elements present in stack" << endl;

	while (!isEmpty(root)) {
		cout << peek(root) << endl;
		pop(&root);
	}

	return 0;
}
