/*
 * 求单链表的中间节点
 */

#include <bits/stdc++.h>
struct ListNode{
    ListNode *next;
    int data;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    int list_middle_number(ListNode *head){
        int totalLen = 0;
        ListNode *temp = head;
        while(temp){
            totalLen++;
            temp = temp->next;
        }
        temp = head;
        for(int i=0; i<totalLen/2; ++i){
            temp = temp->next;
        }
        return temp->data;
    }
};

int main(){
    ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	Solution solve;
	ListNode *head = &a;
	printf("%d\n",solve.list_middle_number(head));
    return 0;
}
