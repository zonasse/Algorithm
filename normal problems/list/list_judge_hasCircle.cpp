#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int data;
    ListNode *next;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    bool judge_hasCircle1(ListNode *head){
        //方法1 集合方法
        set<ListNode*> node_set;
        ListNode *ptr = head;
        while(ptr){
            if(node_set.find(ptr) == node_set.end()){
                node_set.insert(ptr);
            }else{
                return true;
            }
            ptr = ptr->next;
        }
        return false;

    }
    int judge_hasCircle2(ListNode *head){
        if(head == NULL || head->next == NULL){
            return -1;
        }
        ListNode *fast = head->next->next;
        ListNode *slow = head->next;
        while(fast != NULL && fast->next != NULL && fast != slow){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast == slow){
            fast = head;
            while(fast != slow){
                fast = fast->next;
                slow = slow->next;
            }
            return fast->data;
        }
        return -1;
    }

};

int main(){

    return 0;
}
