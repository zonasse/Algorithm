#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    ListNode* list_partition(ListNode *head,int val){
        if(head == NULL){
            return head;
        }
        ListNode *smallPtr = NULL;
        ListNode *smallHead = NULL;
        ListNode *largePtr = NULL;
        ListNode *largeHead = NULL;
        while(head){
            ListNode *nextNode = head->next;
            head->next = NULL;
            if(head->data < val){
                if(smallHead == NULL){
                    smallHead = head;
                    smallPtr = smallHead;
                }else{
                    smallPtr->next = head;
                    smallPtr = smallPtr->next;
                }
            }else{
                if(largeHead == NULL){
                    largeHead = head;
                    largePtr = largeHead;
                }else{
                    largePtr->next = head;
                    largePtr = largePtr->next;
                }
            }
            head = nextNode;
        }
        if(smallHead != NULL){
            smallPtr->next = largeHead;
        }
        return smallHead == NULL ? largeHead:smallHead;
    }

};

int main(){
    return 0;
}
