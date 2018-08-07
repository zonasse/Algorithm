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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1 || !pHead2){
            return NULL;
        }
        set<ListNode*> node_set;
        ListNode *head = pHead1;
        while(head){
            node_set.insert(head);
            head = head->next;
        }
        head = pHead2;
        while(head){
            if(node_set.find(head) != node_set.end()){
                return head;
            }
            head = head->next;
        }
        return NULL;
    }
};
