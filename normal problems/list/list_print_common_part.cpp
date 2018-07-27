#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode *next;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    vector<int>  print_common_part(ListNode *head1,ListNode *head2){
        if(head1 == NULL || head2 == NULL){
            return {};
        }
        vector<int> res;
        while(head1 && head2){
            if(head1->data < head2->data){
                head1 = head1->next;
            }else if(head1->data > head2->data){
                head2 = head2->next;
            }else{
                res.push_back(head1->data);
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        for(int i=0; i<res.size(); ++i){
            printf("%d\n",res[i]);
        }
        return res;
    }
};

int main(){

    return 0;
}
