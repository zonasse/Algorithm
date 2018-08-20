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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode *small = new ListNode(-1);
        ListNode *big = new ListNode(-1);
        ListNode *temp = head;
        ListNode *smallPtr = small;
        ListNode *bigPtr = big;
        while(temp){
            ListNode *next = temp->next;
            temp->next = NULL;
            if(temp->val < x){
                smallPtr->next = temp;
                smallPtr = smallPtr->next;
            }else{
                bigPtr->next = temp;
                bigPtr = bigPtr->next;
            }
            temp = next;
        }
        smallPtr->next = big->next;
        return small->next;
    }
};
