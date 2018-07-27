#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    ListNode* reverse_per_k_number1(ListNode *head,int k){
        stack<ListNode*> node_stack;
        if(head == NULL ||head->next == NULL||k < 2){
            return head;
        }
        ListNode *resHead = NULL;//反转后链表的头结点
        ListNode *header = NULL;//当前转换的头结点
        ListNode *tail = NULL;//当前转换的尾节点
        ListNode *lastTail = NULL;//上次转换的尾节点
        while(head){
            ListNode *nextNode = head->next;
            head->next = NULL;
            node_stack.push(head);
            if(node_stack.size() == k){

                header = tail = node_stack.top();
                node_stack.pop();
                while(node_stack.empty() == false){
                    tail->next = node_stack.top();
                    node_stack.pop();
                    tail = tail->next;
                }
                if(resHead == NULL){
                    resHead = header;
                    lastTail = tail;
                }else{
                    lastTail->next = header;
                    lastTail = tail;
                }
            }
            head = nextNode;
        }
        if(node_stack.empty() == false){
            //头插法插入
            header = node_stack.top();
            header->next = NULL;
            node_stack.pop();
            while(node_stack.empty() == false){
                ListNode *temp = node_stack.top();
                node_stack.pop();
                temp->next = header;
                header = temp;
            }
            lastTail->next = header;
        }
        return resHead;

    }
    ListNode* reverse_per_k_number2(ListNode *head,int k){
        if(!head || !head->next || k < 2){
            return head;
        }
        ListNode *next = NULL;
        ListNode *resHead = NULL;//反转后的链表的头结点
        ListNode *header = NULL, *tail = NULL;//记录每次截取k个元素过程中的头结点和尾结点
        ListNode *lastTail = NULL;//上一次反转过程中的尾结点
        bool flag = true;
        while(flag){
            header = NULL;
            tail = NULL;
            //每次拿出k个元素
            for(int i = 0; i < k; i++){
                if(head == NULL){//表示最后一组不满足k个元素
                    flag = false;
                    break;
                }else{
                    next = head->next;
                    head->next = NULL;
                    if(i == 0){
                        header = head;
                        tail = head;
                    }else{
                        tail->next = head;
                        tail = head;
                    }
                    head = next;
                }
            }
            if(flag){//反转这k个元素
                ListNode *tempListHeader = header;
                ListNode *temp = tempListHeader;
                tempListHeader = tempListHeader->next;
                temp->next = NULL;//摘取出来
                while(tempListHeader != NULL){
                    next = tempListHeader->next;
                    tempListHeader->next = temp;
                    temp = tempListHeader;
                    tempListHeader = next;
                }
                if(resHead == NULL){
                    resHead = tail;
                    lastTail = header;
                }else{
                    lastTail->next = tail;
                    lastTail = header;
                }
            }else{//最后一组不满足k个元素,直接放到反转后的链表后面
                lastTail->next = header;
            }
        }
        return resHead;
    }

};

int main(){
    return 0;
}
