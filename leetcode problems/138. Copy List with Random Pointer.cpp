/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return head;
        RandomListNode *newHead = new RandomListNode(head->label);
        unordered_map<RandomListNode*,RandomListNode*> node_map;
        node_map[head] = newHead;
        RandomListNode* node = newHead;
        RandomListNode* cur = head->next;

        while(cur){
            RandomListNode* copyNode = new RandomListNode(cur->label);
            node->next = copyNode;
            node_map[cur] = copyNode;
            node = node->next;
            cur = cur->next;
        }

        node = newHead;
        cur = head;
        while(cur){
            node->random = node_map[cur->random];
            cur = cur->next;
            node = node->next;
        }
        return newHead;
    }
};
