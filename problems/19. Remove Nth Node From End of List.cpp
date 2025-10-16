/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // count number of ListNode*
        // move pointer to p-1 = count - n -1;
        // delete p
        // need to check case n = cound (first Node, Head)
        // Result 0ms, 14.82MB (91,32%)
        if (!head) return nullptr;
        ListNode* cur = head;
        int count =0;
        while(cur !=nullptr){
            count++;
            cur = cur->next;
        }
        if(n==count){
            ListNode* newHead = head -> next;
            delete head;
            return newHead;
        }
        ListNode* p = head;
        for(int i =0; i <count -n-1; i++){
            p = p->next;
        }
        if(p && p->next){
            ListNode* temp = p->next;
            p->next = p->next->next;
            delete temp; 
        }
        return head;
    }
};