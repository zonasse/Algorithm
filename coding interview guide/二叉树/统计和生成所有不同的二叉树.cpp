//
// Created by 钟奇龙 on 2019-05-04.
//
#include <iostream>
#include <vector>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL){}
};

int numTrees(int n){
    if(n < 2) return 1;
    vector<int> num(n+1);
    num[0] = 1;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=i; ++j){
            num[i] += num[j-1] * num[i-j];
        }
    }
    return num[n];
}

Node* cloneTree(Node* head){
    if(!head) return NULL;
    Node *newHead = new Node(head->data);
    newHead->left = cloneTree(head->left);
    newHead->right = cloneTree(head->right);
    return newHead;
}
vector<Node*> generate(int start,int end){
    vector<Node*> res;
    if(start > end){
        res.push_back(NULL);
    }
    for(int i=start; i<=end; ++i){
        Node* head = new Node(i);
        vector<Node*> leftNodes = generate(start,i-1);
        vector<Node*> rightNodes = generate(i+1,end);
        for(Node* left : leftNodes){
            for(Node* right : rightNodes){
                head->left = left;
                head->right = right;
                res.push_back(cloneTree(head));
            }
        }
    }
    return res;
}

vector<Node*> generateTrees(int n){
    return generate(1,n);
}

int main(){
    cout<<numTrees(5)<<endl;
    vector<Node*> trees = generateTrees(5);

    return 0;
}