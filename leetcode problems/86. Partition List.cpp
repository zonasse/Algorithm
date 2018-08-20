/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *pre = newHead;
        while(pre->next && pre->next->val < x) pre = pre->next;
        ListNode *cur = pre;
        while(cur->next){
            if(cur->next->val < x){
                ListNode *nextNode = cur->next;
                cur->next = nextNode->next;
                nextNode->next = pre->next;
                pre->next = nextNode;
                pre = pre->next;
            }else{
                cur = cur->next;
            }
        }
        return newHead->next;
    }
};
