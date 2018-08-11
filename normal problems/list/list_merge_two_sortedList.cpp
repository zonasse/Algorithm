/*
 *  合并两个有序单链表
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    ListNode *next;
    int data;
    ListNode(int x):next(NULL),data(x){}
};

class Solution{
public:
    ListNode* merge_two_sortedList(ListNode *head1,ListNode *head2){
        //创建出额外的头结点便于保存结果
        ListNode *ans = new ListNode(-1);
        while(head1 && head2){
            if(head1->data < head2->data){
                ans->next = head1;
                head1 = head1->next;
            }else{
                ans->next = head2;
                head2 = head2->next;
            }
        }
        if(head1){
            ans->next = head1;
        }
        if(head2){
            ans->next = head2;
        }
        return ans->next;
    }
};
int main(){
    return 0;
}
