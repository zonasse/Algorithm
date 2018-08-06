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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        int len = 0;
        ListNode *temp = pListHead;
        while(temp){
            len++;
            temp = temp->next;
        }
        if(len < k){
            return NULL;
        }

        ListNode *p1 = pListHead;
        ListNode *p2 = pListHead;
        while(k--){
            p1 = p1->next;
        }
        while(p1 && p2){
            p1 = p1->next;
            p2 = p2->next;
            if(p1 == NULL){
                return p2;
            }
        }
        return p2;
    }
};
