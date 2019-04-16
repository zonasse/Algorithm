//
// Created by 钟奇龙 on 2019-04-16.
//

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int x):data(x),next(NULL){

    }
};

int abs(int n){
    return n>0?n:-n;
}
//获取循环节点
Node* getLoopNode(Node *head){
    if(!head || !head->next || !head->next->next) return NULL;
    Node *slow = head->next;
    Node *fast = head->next->next;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = head;
    while(fast != slow){
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}
//获取两个非循环链表的相交节点
Node* bothNoLoop(Node *head1, Node *head2){
    if(!head1 || !head2) return NULL;
    int n = 0;
    Node *p1 = head1;
    Node *p2 = head2;
    while(p1->next){
        n++;
        p1 = p1->next;
    }
    while(p2->next){
        n--;
        p2 = p2->next;
    }
    if(p1 != p2){
        return NULL;
    }
    p1 = n > 0 ? head1:head2;
    p2 = p1 == head1 ? head2:head1;
    n = abs(n);
    while(n--){
        p1 = p1->next;
    }
    while(p1 != p2){
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}
//获取两个循环链表的相交节点
Node* bothLoop(Node *head1,Node *loop1,Node *head2, Node *loop2){
    //循环节点相同
    if(loop1 == loop2){
        int n = 0;
        Node *p1 = head1;
        Node *p2 = head2;
        while(p1 != loop1){
            n++;
            p1 = p1->next;
        }
        while(p2 != loop2){
            n--;
            p2 = p2->next;
        }
        p1 = n > 0 ? head1:head2;
        p2 = p1 == head1? head2:head1;
        n = abs(n);
        while(n--){
            p1 = p1->next;
        }
        while(p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }else{//循环节点不同
        Node *p1 = loop1->next;
        while(p1 != loop1){
            if(p1 == loop2){
                return loop2;
            }
            p1 = p1->next;
        }
        return NULL;
    }

}

Node* getIntersectNode(Node *head1,Node *head2){
    if(!head1 || !head2){
        return NULL;
    }
    Node *loop1 = getLoopNode(head1);
    Node *loop2 = getLoopNode(head2);
    if(loop1 && loop2){
        return bothLoop(head1,loop1,head2,loop2);
    }else if(!loop1 && !loop2){
        return bothNoLoop(head1,head2);
    }else{
        return NULL;
    }
}