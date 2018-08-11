#include <bits/stdc++.h>
using namespace std;
/*
 * 用单链表模拟大数加法，链表为逆序存储，个位位于链表头
 */
struct ListNode{
    int data;
    ListNode *next;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    ListNode* bigNumber_plus(ListNode *head1,ListNode *head2){
        if(!head1){
            return head2;
        }
        if(!head2){
            return head1;
        }
        ListNode *ptr1 = head1;
        ListNode *ptr2 = head2;
        //创建出额外的头结点便于存储结果
        ListNode *result = new ListNode(0);
        ListNode *resultPtr = result;
        int carry = 0;
        while(ptr1 && ptr2){
            int num = ptr1->data + ptr2->data + carry;

            ListNode *tempNode = new ListNode(num % 10);
            carry = num / 10;
            resultPtr->next = tempNode;
            resultPtr = resultPtr->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        while(ptr1){
            int num = ptr1->data + carry;
            carry = num / 10;
            ListNode *tempNode = new ListNode(num % 10);
            ptr1 = ptr1->next;
            resultPtr->next = tempNode;
            resultPtr = resultPtr->next;
        }
        while(ptr2){
            int num = ptr2->data + carry;
            carry = num / 10;
            ListNode *tempNode = new ListNode(num % 10);
            ptr2 = ptr2->next;
            resultPtr->next = tempNode;
            resultPtr = resultPtr->next;
        }
        if(carry){
            ListNode *tempNode = new ListNode(carry);
            resultPtr->next = tempNode;
            resultPtr = resultPtr->next;
        }
        return result->next;
    }
};

int main(){
    return 0;
}
