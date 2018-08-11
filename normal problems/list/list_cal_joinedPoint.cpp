/*
 *  单链表计算相交点
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    ListNode* next;
    int data;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    int cal_joinedPoint(ListNode *head1,ListNode *head2){
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
        if(len1 > len2){
            for(int i=0; i<len1-len2; ++i){
                head1 = head1->next;
            }
        }else{
            for(int i=0; i<len2-len1; ++i){
                head2 = head2->next;
            }
        }
        while(head1 && head2 && head1 != head2){
            head1 = head1->next;
            head2 = head2->next;
        }
        return head1->data;
    }

};

int main(){
    return 0;
}
