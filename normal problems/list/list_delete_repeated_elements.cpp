#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    ListNode* delete_repeated_elements(ListNode *head){
        if(head == NULL){
            return head;
        }
        set<int> node_set;
        ListNode *prev = head;
        node_set.insert(prev->val);
        ListNode *headPtr = prev->next;
        while(headPtr){
            if(node_set.find(headPtr->val) == node_set.end()){
                node_set.insert(headPtr->val);
                headPtr = headPtr->next;
                prev = prev->next;
            }else{
                prev->next = prev->next->next;
                headPtr = prev->next;
            }
        }
        return head;
    }

};
int main(){

    return 0;
}
