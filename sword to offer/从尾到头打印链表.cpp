/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        travel(head,res);
        return res;
    }
    void travel(ListNode* head,vector<int> &res){
        if(!head){
            return;
        }
        travel(head->next,res);
        res.push_back(head->val);
    }
};
