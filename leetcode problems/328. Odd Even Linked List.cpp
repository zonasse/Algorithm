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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        int index = 1;
        ListNode *odd = new ListNode(-1);
        ListNode *even = new ListNode(-1);
        ListNode *p1 = odd;
        ListNode *p2 = even;
        while(head){
            ListNode *cur = head;
            head = head->next;
            cur->next = NULL;
            if(index % 2 == 1){
                p1->next = cur;
                p1 = p1->next;
            }else{
                p2->next = cur;
                p2 = p2->next;
            }
            index++;
        }
        even = even->next;
        p1->next = even;
        return odd->next;

    }
};
