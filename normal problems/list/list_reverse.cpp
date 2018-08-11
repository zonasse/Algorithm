/*
 *  反转单链表
 */
#include <bits/stdc++.h>

struct ListNode{
    ListNode *next;
    int data;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    ListNode* list_reverse(ListNode *head){
        ListNode *newHead = NULL;
        while(head){
            ListNode *nextNode = head->next;
            head->next = newHead;
            newHead = head;
            head = nextNode;
        }
        return newHead;
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
	printf("Before reverse:\n");
	while(head){
		printf("%d\n", head->data);
		head = head->next;
	}
	head = solve.list_reverse(&a);
	printf("After reverse:\n");
	while(head){
		printf("%d\n", head->data);
		head = head->next;
	}

    return 0;
}
