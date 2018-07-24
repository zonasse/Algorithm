#include <bits/stdc++.h>

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    bool list_judge_two_joined_hasCircle(ListNode *head1,ListNode *head2){
        if(head1 == NULL || head2 == NULL){
            return false;
        }
        ListNode *loopStartNode1 = getLoopNode(head1);
        ListNode *loopStartNode2 = getLoopNode(head2);
        if(loopStartNode1 == NULL || loopStartNode2 == NULL){
            return false;
        }
        if(loopStartNode1 == loopStartNode2){
            return true;
        }else{
            ListNode *temp = loopStartNode1->next;
            while(temp != loopStartNode1){
                if(temp == loopStartNode2){
                    return true;
                }
                temp = temp->next;
            }
        }
        return false;
    }
    ListNode* getLoopNode(ListNode *head){
        ListNode *fast = head->next->next;
        ListNode *slow = head->next;
        while(fast != NULL && fast ->next != NULL && fast != slow){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast == slow){
            fast = head;
            while(fast != slow){
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
        return NULL;

    }
};
int main(){

    return 0;
}
