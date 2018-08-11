/*
 *  判断回文单链表
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    ListNode *next;
    int data;
};

class Solution{
public:
    bool isPalindrome1(ListNode *head){
        //方法1：借助栈和两次遍历
        if(head == NULL){
            return false;
        }
        stack<ListNode *> support;
        ListNode* temp = head;
        while(temp){
            support.push(temp);
            temp = temp->next;
        }
        temp = head;
        while(temp){
            ListNode *stackElement = support.top();
            if(temp->data != stackElement->data){
                return false;
            }
            support.pop();
            temp = temp->next;
        }
        return true;
    }
    bool isPalindrome2(ListNode *head){
        //方法2：借助栈和一次遍历
        if(head == NULL){
            return head;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        stack<ListNode*> support;
        int nodeCount = 0;
        //遍历拿到前一半数据
        while(fast){
            if(fast->next == NULL){//节点数为奇数
                slow = slow->next;
                break;
            }
            support.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        //后一半与前一半数据对比
        while(slow){
            ListNode *temp = support.top();
            if(slow->data != temp->data){
                return false;
            }
            support.pop();
            slow = slow->next;
        }
        return true;
    }
    bool isPalindrome3(ListNode *pHead){
        //方法3.不借助栈，反转后半部分链表
        if(pHead == NULL){
            return false;
        }
        ListNode *fast = pHead;
        ListNode *slow = pHead;
        ListNode *lastHead = NULL;
        while(fast->next != NULL && fast->next->next != NULL){//寻找到慢指针指向的中点
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next != NULL){//表示链表节点数量为偶数
            lastHead = slow->next;
        }else{
            lastHead = slow;
        }
        ListNode *head = lastHead;//指向反转后的头结点
        lastHead = lastHead->next;
        ListNode *next = NULL;
        head->next = NULL;
        while(lastHead){//反转链表
            next = lastHead->next;
            lastHead->next = head;
            head = lastHead;
            lastHead = next;
        }
        bool res = true;
        ListNode *tempList = head;
        while(tempList != NULL && pHead != NULL){
            if(tempList->data != pHead->data){
                res = false;
                break;
            }
            tempList = tempList->next;
            pHead = pHead->next;
        }
        //再把后面反转的链表反转回来
        ListNode *head2 = head;
        head = head->next;
        head2->next = NULL;
        while(head != NULL){
            next = head->next;
            head->next = head2;
            head2 = head;
            head = next;
        }
        slow->next = head2;
        return res;

    }

};
int main(){
    return 0;
}
