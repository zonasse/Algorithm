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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *newHead = NULL;
        while(pHead){
            ListNode *next = pHead->next;
            pHead->next = newHead;
            newHead = pHead;
            pHead = next;
        }
        return newHead;
    }
};
