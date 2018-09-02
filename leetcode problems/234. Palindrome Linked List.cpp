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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        fast = slow->next;
        slow->next = NULL;
        /*
         * reverse head2
         */
        ListNode *head2 = NULL;
        while(fast){
            ListNode *next = fast->next;
            fast->next = head2;
            head2 = fast;
            fast = next;
        }
        ListNode *p2 = head2;
        ListNode *p1 = head;
        bool flag = true;
        while(p2){
            if(p1->val != p2->val){
                flag = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        /*
         * recovery list
         */
        fast = NULL;
        while(head2){
            ListNode *next = head2->next;
            head2->next = fast;
            fast = head2;
            head2 = next;
        }
        slow->next = fast;
        return flag;
    }
};
