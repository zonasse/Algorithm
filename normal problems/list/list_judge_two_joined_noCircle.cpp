/*
 * 判断两个无环单链表是否相交
 */
#include <bits/stdc++.h>

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    bool list_judge_two_joined_noCircle(ListNode *head1,ListNode *head2){
        int len1 = 0;
        int len2 = 0;
        ListNode *temp = head1;
        while(temp){
            len1++;
            temp = temp->next;
        }
        temp = head2;
        while(temp){
            len2++;
            temp = temp->next;
        }
        ListNode *temp1 = head1;
        ListNode *temp2 = head2;
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
    }


};
int main(){

    return 0;
}
