#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int data;
    ListNode *next;
    ListNode *random;
    ListNode(int x):data(x),next(NULL),random(NULL){}
};
//1.复制连接法
class Solution1{
public:
    ListNode* copyListWithRandomPoint(ListNode *head){
             if(head == NULL){
            return head;
        }
        //1.第一遍遍历，复制新节点到当前节点之后
        ListNode *list = head;
        while(list != NULL){
            ListNode *copyNode = new ListNode(list->data);
            copyNode->next = list->next;
            list->next = copyNode;
            list = list->next->next;
        }
        //2.第二遍遍历，设置新节点的random指针
        list = head;
        while(list){
            ListNode *copyNode = list->next;
            if(list->random){
                copyNode->random = list->random->next;
            }else{
                copyNode->random = NULL;//此步不是必须，初始化时已为NULL
            }
            list = list->next->next;
        }
        //3.第三次遍历，还原原始链表，提取出新链表
        list = head;
        ListNode *newHead = head->next;
        while(list){
            ListNode *temp = list->next;
            list->next = temp->next;
            if(temp->next){
                temp->next = temp->next->next;
            }
            list = list->next;
        }
        return newHead;
    }
};
//2.hash法
class Solution{
public:
    ListNode* copyListWithRandomPoint(ListNode *head){
        if(head == NULL){
            return head;
        }
        vector<ListNode*> node_vec;
        map<ListNode*,int> node_map;
        int index = 0;
        ListNode *ptr = head;
        while(ptr){
            node_vec.push_back(new ListNode(ptr->data));
            node_map[ptr] = index;
            index++;
            ptr = ptr->next;
        }
        node_vec.push_back(0);
        index = 0;
        ptr = head;
        while(ptr){
            node_vec[index]->next = node_vec[index+1];
            if(ptr->random){
                int id = node_map[ptr->random];
                node_vec[index]->random = node_vec[id];
            }
            ptr = ptr->next;
            index++;
        }
        return node_vec[0];
    }
};
int main(){
    return 0;
}
