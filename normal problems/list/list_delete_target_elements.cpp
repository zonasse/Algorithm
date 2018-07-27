#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    ListNode* delete_target_elements(ListNode* head,int val){
        if(!head){
            return head;
        }
        ListNode *newHead = NULL;
        ListNode *newTail = NULL;
        while(head){
            ListNode *nextNode = head->next;
            head->next = NULL;
            if(nextNode->data != val){
                if(!newHead){
                    newHead = head;
                    newTail = newHead;
                }else{
                    newTail->next = head;
                    newTail = newTail->next;
                }
            }
            head = nextNode;
        }
        return newHead;
    }

};
