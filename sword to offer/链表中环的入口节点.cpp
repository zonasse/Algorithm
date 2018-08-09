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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead || !pHead->next){
            return NULL;
        }
        ListNode *slow = pHead->next;
        ListNode *fast = pHead->next->next;
        while(slow && fast && slow != fast){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(slow == fast){
            fast = pHead;
            while(fast != slow){
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
        return NULL;
    }
};
