#include<iostream>
#include<vector>
#include <stack>
#include "Solution.h"
using namespace std;

//Definition for singly-linked list.



ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode ans(0);
    ListNode* cur = &ans; // cur point to ans then ans.next = cur -> next. update val of cur ~ update val of ans
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int x = (l1 != nullptr) ? l1->val : 0;
        int y = (l2 != nullptr) ? l2->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }
    return ans.next;
}
ListNode* Solution::createList(std::vector<int> vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int v : vals) {
        ListNode* node = new ListNode(v);
        if (!head) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}
void Solution::printListNode(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}