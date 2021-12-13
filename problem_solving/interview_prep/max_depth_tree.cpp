#include <bits/stdc++.h>
using namespace std;
 
class node {
    public:
    int data;
    node* left;
    node* right;
};

node* newNode(int data) {
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
     
    return(Node);
}

int maxDepth(node* node) {
    if (node == NULL) {
        return -1;
    }

    int leftDepth = maxDepth(node->left);
    int rightDepth = maxDepth(node->right);

    return max(leftDepth + 1, rightDepth + 1);
}

// Driver code   
int main() {
    node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
     
    cout << "Height of tree is " << maxDepth(root);
    return 0;
}