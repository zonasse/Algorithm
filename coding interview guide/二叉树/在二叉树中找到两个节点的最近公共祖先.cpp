//
// Created by 钟奇龙 on 2019-05-03.
//

#include <iostream>
#include <map>
#include <set>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL){}
};
//普通解法
Node* getCommonAncestor(Node *root,Node *node1,Node *node2){
    if(!root || root == node1 || root == node2) return root;
    Node *left = getCommonAncestor(root->left,node1,node2);
    Node *right = getCommonAncestor(root->right,node1,node2);
    if(left && right){
        return root;
    }
    return left == NULL ? right:left;
}

//哈希表解法
map<Node*,Node*> ancestor_map;
void setNodeMap(Node *root){
    if(!root) return;
    if(root->left){
        ancestor_map[root->left] = root;
    }
    if(root->right){
        ancestor_map[root->right] = root;
    }
    setNodeMap(root->left);
    setNodeMap(root->right);
}
Node* query(Node* node1,Node* node2){
    set<Node*> ancestor_set;
    while(ancestor_map.find(node1) != ancestor_map.end()){
        ancestor_set.insert(ancestor_map[node1]);
        node1 = ancestor_map[node1];
    }
    while(ancestor_set.find(node2) == ancestor_set.end()){
        node2 = ancestor_map[node2];
    }
    return node2;
}