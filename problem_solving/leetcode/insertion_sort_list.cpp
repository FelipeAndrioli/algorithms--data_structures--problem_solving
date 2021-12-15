#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insertionSortList(ListNode* head) {
    // Create a new starting point to the new list
    ListNode* sorted_list = new ListNode();
    
    // Keep track of the current node
    ListNode* current = head;
    
    while (current != nullptr) {
        // Insert element in the resulting list
        ListNode* previous = sorted_list;
        
        // Find the position to insert the current node
        while (previous->next != nullptr && previous->next->val < current->val) {
            previous = previous->next;
        }
        
        ListNode* next = current->next;
        
        // Insert the current node to the new list
        current->next = previous->next;
        previous->next = current;
        
        // Next iteration
        current = next;
    }
    
    // The first value is always going to be 0, so we need to return the next
    return sorted_list->next;
}