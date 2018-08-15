/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k < 2) return head;
        ListNode *cur = head;
        ListNode *pre = NULL;
        ListNode *start = NULL;
        int index = 1;
        while(cur){
            ListNode *next = cur->next;
            if(index == k){
               start = pre == NULL? head:pre->next;
                head = pre == NULL? cur:head;
                reverseK(pre,start,cur,next);
                pre = start;
                index = 0;
            }
            index++;
            cur = next;
        }
        return head;
    }
    void reverseK(ListNode *left,ListNode *start,ListNode *end,ListNode *right){
        ListNode *pre = start;
        ListNode *cur = start->next;
        while(cur != right){
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        if(left){
            left->next = end;
        }
        start->next = right;
    }
}
