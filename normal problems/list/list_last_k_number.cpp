#include <bits/stdc++.h>

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    int list_last_k_number(ListNode *head,int k){
        int totalLen = 0;
        ListNode *temp = head;
        while(temp){
            totalLen++;
            temp = temp->next;
        }
        if(totalLen < k){
            return -1;
        }
        temp = head;
        //快指针先走K步
        for(int i=0; i<k; ++i){
            temp = temp->next;
        }
        while(temp){
            temp = temp->next;
            head = head->next;
        }
        return head->data;
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
	for(int k=1; k<=6; ++k){
        ListNode *temp = &a;
        int result = solve.list_last_k_number(temp,k);
        printf("k = %d,result = %d\n",k,result);
	}

    return 0;
}
