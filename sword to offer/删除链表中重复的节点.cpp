/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead || !pHead->next){
            return pHead;
        }
        ListNode *newHead = new ListNode(-1);
        newHead->next = pHead;

        ListNode *pre = newHead;
        ListNode *ptr = pre->next;
        while(ptr && ptr->next){
            ListNode* nextNode = ptr->next;
            if(ptr->val == nextNode->val){
                while(nextNode&& nextNode->val == ptr->val){
                    nextNode = nextNode->next;
                }
                pre->next = nextNode;
                ptr = pre->next;
            }else{
                pre = ptr;
                ptr = ptr->next;
            }
        }
        return newHead->next;
    }
};
