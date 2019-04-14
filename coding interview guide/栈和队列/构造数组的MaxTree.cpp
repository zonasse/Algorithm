//
// Created by 钟奇龙 on 2019-04-14.
//
#include <stack>
#include <map>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int num):data(num),left(NULL),right(NULL){

    }
};

void popStackAndSetMap(stack<Node*> &s,map<Node*,Node*> &bigMap){
    Node* curNode = s.top();
    s.pop();
    if(s.empty() == true){
        bigMap[curNode] = NULL;
    }else{
        bigMap[curNode] = s.top();
    }
}

Node* getMaxTree(vector<int> arr){
    if(arr.size() == 0) return NULL;
    map<Node*,Node*> lBigMap;
    map<Node*,Node*> rBigMap;
    vector<Node*> nodeArr;
    for (int i = 0; i < arr.size(); ++i) {
        Node *curNode = new Node(arr[i]);
        nodeArr.push_back(curNode);
    }
    stack<Node*> supportS;
    //设置左边第一个最大值
    for (int i = 0; i < nodeArr.size(); ++i) {
        Node* curNode = nodeArr[i];
        while(supportS.empty() == false && supportS.top()->data < curNode->data){
            popStackAndSetMap(supportS,lBigMap);
        }
        supportS.push(curNode);
    }
    while(supportS.empty() == false){
        popStackAndSetMap(supportS,lBigMap);
    }

    //设置右边第一个最大值
    for (int i = nodeArr.size()-1; i >= 0; --i) {
        Node* curNode = nodeArr[i];
        while(supportS.empty() == false && supportS.top()->data < curNode->data){
            popStackAndSetMap(supportS,rBigMap);
        }
        supportS.push(curNode);
    }
    while(supportS.empty() == false){
        popStackAndSetMap(supportS,rBigMap);
    }

    //构造树
    Node* head = NULL;
    for (int i = 0; i < nodeArr.size(); ++i) {
        Node* curNode = nodeArr[i];
        Node *leftNode = lBigMap[curNode];
        Node *rightNode = rBigMap[curNode];
        if(!leftNode && !rightNode){
            head = curNode;
        }else if(!leftNode){
            if(rightNode->left){
                rightNode->right = curNode;
            }else{
                rightNode->left = curNode;
            }
        }else if(!rightNode){
            if(leftNode->left){
                leftNode->right = curNode;
            }else{
                leftNode->left = curNode;
            }
        }else{
            Node *parent = leftNode->data < rightNode->data ? leftNode:rightNode;
            if(parent->left){
                parent->right = curNode;
            }else{
                parent->left = curNode;
            }
        }
    }
    return head;
}

//int main(){
//    Node *tree = getMaxTree({3,4,5,1,2});
//
//
//    return 0;
//}