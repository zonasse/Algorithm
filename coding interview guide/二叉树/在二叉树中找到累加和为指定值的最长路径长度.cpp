//
// Created by 钟奇龙 on 2019-05-01.
//
#include <iostream>
#include <map>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL){}
};
int preorderFind(Node *root,int target,int preSum,int level,int maxLen,map<int,int> &sumMap){
    if(!root) return maxLen;
    int curSum = root->data + preSum;
    if(sumMap.find(curSum) == sumMap.end()){
        sumMap[curSum] = level;
    }
    if(sumMap.find(curSum - target) != sumMap.end()){
        maxLen = max(maxLen,level - sumMap[curSum-target]);
    }
    maxLen = preorderFind(root->left,target,curSum,level+1,maxLen,sumMap);
    maxLen = preorderFind(root->right,target,curSum,level+1,maxLen,sumMap);
    if(sumMap[curSum] == level){
        sumMap.erase(curSum);
    }
    return maxLen;
}
int getMaxLength(Node *root,int target){
    map<int,int> sumMap;
    sumMap[0] = 0;
    return preorderFind(root,target,0,1,0,sumMap);
}

int main(){

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node5->right = node7;

    cout<<getMaxLength(node1,15)<<endl;
    return 0;
}