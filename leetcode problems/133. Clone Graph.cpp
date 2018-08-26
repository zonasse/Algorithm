/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int,UndirectedGraphNode*> node_map;
        return clone(node,node_map);
    }
    UndirectedGraphNode* clone(UndirectedGraphNode* node,unordered_map<int,UndirectedGraphNode*> &node_map){
        if(!node) return node;
        if(node_map.count(node->label)){
            return node_map[node->label];
        }
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        node_map[node->label] = newNode;
        for(int i=0; i<node->neighbors.size(); ++i){
            newNode->neighbors.push_back(clone(node->neighbors[i],node_map));
        }
        return newNode;
    }
};
