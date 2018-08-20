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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *pre = newHead;
        while(pre->next){
            ListNode *cur = pre->next;
            while(cur->next && cur->next->val == cur->val) cur = cur->next;
            if(pre->next != cur){
                pre->next = cur;
            }else{
                pre = pre->next;
            }
        }
        return newHead->next;
    }
};
