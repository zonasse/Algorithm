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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || m == n) return head;
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *preTail = NULL;
        ListNode *lastTail = NULL;
        ListNode *start = NULL;
        ListNode *end = NULL;
        ListNode *cur = newHead;
        for(int i=1; i<m; ++i){
            cur = cur->next;
        }
        preTail = cur;
        start = cur->next;
        cur = start;
        preTail->next = NULL;
        for(int i=1; i<=n-m; ++i){
            cur = cur->next;
        }
        end = cur;
        lastTail = cur->next;
        resign(preTail,start,end,lastTail);
        return newHead->next;
    }
    void resign(ListNode *preTail,ListNode *start,ListNode *end,ListNode *lastTail){
        ListNode *pre = start;
        ListNode *cur = start->next;
        while(cur != lastTail){
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        if(preTail){
            preTail->next = pre;
        }
        start->next = lastTail;
    }
};
