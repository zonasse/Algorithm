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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode *temp = head;
        int len = 1;
        while(temp->next){
            temp = temp->next;
            len++;
        }
        k %= len;
        if(k == 0) return head;
        ListNode *tail = temp;
        temp = head;
        for(int i=1; i<=len-k-1; ++i){
            temp = temp->next;
        }
        ListNode *newHead = temp->next;
        tail->next = head;
        temp->next = NULL;
        return newHead;
    }
};
