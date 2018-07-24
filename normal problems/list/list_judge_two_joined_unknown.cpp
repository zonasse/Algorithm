#include <bits/stdc++.h>

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    bool list_judge_two_joined_unknown(ListNode *head1,ListNode *head2){
        //3种情况：
        //1.若一个有环另一个没有，则返回false
        //2.两个都有环
        //3.两个都没有环
        ListNode *loopNode1 = getLoopNode(head1);
        ListNode *loopNode2 = getLoopNode(head2);
        if(loopNode1 && loopNode2){
            //都有环
            if(loopNode1 == loopNode2){
                return true;
            }
            ListNode *temp = loopNode1->next;
            while(temp != loopNode1){
                if(temp == loopNode2){
                    return true;
                }
                temp = temp->next;
            }
        }else if(loopNode1 == NULL && loopNode2 == NULL){
            //都无环
            int len1 = 0;
            int len2 = 0;
            ListNode *temp = loopNode1;
            while(temp){
                len1++;
                temp = temp->next;
            }
            temp = loopNode2;
            while(temp){
                len2++;
                temp = temp->next;
            }
            ListNode *temp1 = loopNode1;
            ListNode *temp2 = loopNode2;
            if(len1 > len2){
                for(int i=0; i<len1-len2; ++i){
                    temp1 = temp1->next;
                }
            }else{
                for(int i=0; i<len2-len1; ++i){
                    temp2 = temp2->next;
                }
            }
            while(temp1 && temp2){
                if(temp1 == temp2){
                    return true;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return false;
        }else{
            return false;
        }
    }
    ListNode* getLoopNode(ListNode *head){
        ListNode *fast = head->next->next;
        ListNode *slow = head->next;
        while(fast != NULL && fast->next != NULL && fast != slow){
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
