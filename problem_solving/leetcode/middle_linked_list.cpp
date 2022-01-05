#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ListNode* middleNodeOptimized(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* middleNode(ListNode* head) {
    ListNode* helper = head;
    int length = 0;

    while (helper) {
        length++;
        helper = helper->next;
    }

    int middle = length / 2;

    helper = head;

    while (helper && middle--) {
        helper = helper->next;
    }

    return helper;
}