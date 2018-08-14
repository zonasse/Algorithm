/*
 * 方法一：小根堆
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*struct cmp{
    bool operator ()(ListNode *l1,ListNode *l2){
        return l1->val < l2->val;
    }
};*/
class Solution1 {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() < 1) return NULL;
        //priority_queue<ListNode*,vector<ListNode*>,cmp> Q;
        priority_queue<int,vector<int>,greater<int> > Q;
        for(int i=0; i<lists.size(); ++i){
            ListNode *temp = lists[i];
            while(temp){
                Q.push(temp->val);
                temp = temp->next;
            }
        }
        ListNode *newHead = new ListNode(-1);
        ListNode *temp = newHead;
        while(Q.empty() == false){
            temp->next = new ListNode(Q.top());
            Q.pop();
            temp = temp->next;
        }
        return newHead->next;
    }
};
/*
 * 方法二：归并排序
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() < 1) return NULL;
        ListNode *head = mergeK(lists,0,lists.size()-1);
        return head;
    }
    ListNode* mergeK(vector<ListNode*> &lists,int left,int right){
        if(left >= right) return lists[left];
        int mid = left + (right-left)/2;
        ListNode *l1 = mergeK(lists,left,mid);
        ListNode *l2 = mergeK(lists,mid+1,right);
        return mergeTwo(l1,l2);
    }
    ListNode* mergeTwo(ListNode *l1,ListNode *l2){
        if(!l1 && !l2) return NULL;
        if(!l1 || !l2) return !l1? l2:l1;
        ListNode *head = new ListNode(-1);
        ListNode *temp = head;
        while(l1 && l2){
            if(l1->val < l2->val){
                temp->next = l1;
                l1 = l1->next;
            }else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if(l1){
            temp->next = l1;
        }
        if(l2){
            temp->next = l2;
        }
        return head->next;
    }
};
