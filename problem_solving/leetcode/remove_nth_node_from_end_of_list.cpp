#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* helper = head;
    int length = 0;
    int i = 0;
    
    while (helper) {
        length++;
        helper = helper->next;
    }

    if (length == n) {
        return head->next;
    }

    for (helper = head; i < length - n; i++) {
        helper = helper->next;
    }

    helper->next = helper->next->next;

    return head;
}