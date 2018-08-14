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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *pre = newHead;
        while(pre->next && pre->next->next){
            ListNode *nNode = pre->next;
            ListNode *nnNode = nNode->next;
            nNode->next = nnNode->next;
            pre->next = nnNode;
            nnNode->next = nNode;
            pre = nNode;
        }
        return newHead->next;
    }
};
