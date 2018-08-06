/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* head)
    {
        if(head == NULL){
            return head;
        }
        vector<RandomListNode*> node_vec;
        map<RandomListNode*,int> node_map;
        int index = 0;
        RandomListNode *ptr = head;
        while(ptr){
            node_vec.push_back(new RandomListNode(ptr->label));
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
