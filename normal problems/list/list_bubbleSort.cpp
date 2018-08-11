/*
 *  µ•¡¥±Ì√∞≈›≈≈–Ú
 */
#include <bits/stdc++.h>

struct listNode{
    listNode *next;
    int data;
    listNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    void bubbleSort(listNode *head){
        for(listNode *p = head; p != NULL; p = p->next){
            for(listNode *q = p->next; q != NULL; q = q->next){
                if(p->data > q->data){
                    int temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }

            }
        }
    }
};

int main(){
    listNode a(5);
    listNode b(4);
    listNode c(6);
    listNode d(3);
    listNode e(1);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    Solution solve;
    listNode *head = &a;
    printf("Before sort:\n");
    while(head){
        printf("%d\n",head->data);
        head = head->next;
    }
    head = &a;
    solve.bubbleSort(head);
    printf("After sort:\n");
    while(head){
        printf("%d\n",head->data);
        head = head->next;
    }
    return 0;
}
