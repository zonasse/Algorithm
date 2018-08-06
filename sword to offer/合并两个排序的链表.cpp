/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *ret = new ListNode(-1);
        ListNode *newHead = ret;
        while(pHead1 && pHead2){
            if(pHead1->val < pHead2->val){
                ret->next = pHead1;
                pHead1 = pHead1->next;
            }else{
                ret->next = pHead2;
                pHead2 = pHead2->next;
            }
            ret = ret->next;
        }
        if(pHead1){
            ret->next = pHead1;
        }
        if(pHead2){
            ret->next = pHead2;
        }
        return newHead->next;
    }
};
