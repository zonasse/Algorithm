#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    /*
    * 默认输入链表已有序，inputArray为输入环形链表数组，nextArray[i]代表inputArray[i]的下一个位置
    */
    ListNode* insert_to_circleList(vector<int> inputArray,vector<int> nextArray,int val){
        //创建环形链表
        //创建新插入的节点
        ListNode *insertNode = new ListNode(val);
        if(inputArray == NULL || inputArray.size() == 0){
            return insertNode;
        }
        ListNode *head = new ListNode(inputArray[0]);
        ListNode *temp = head;
        for(int i=0; i<inputArray.size()-1; ++i){
            ListNode *tempNode = new ListNode(inputArray[nextArray[i]]);
            temp->next = tempNode;
            temp = temp->next;
        }
        //若当前插入值小于头结点值，则插入头结点之前
        if(val < head->data){
            temp->next = insertNode;
            insertNode->next = head;
            return insertNode;
        }
        //插入中间某位置
        ListNode *prev = head;
        ListNode *cur = prev->next;
        while(cur){
            if(prev->data < val && cur->data > val){
                break;
            }
            prev = prev->next;
            cur = prev->next;
        }
        prev->next = insertNode;
        insertNode->next = cur;
        return head;

    }


};
