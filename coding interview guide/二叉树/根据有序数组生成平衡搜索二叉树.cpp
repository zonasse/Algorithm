//
// Created by 钟奇龙 on 2019-05-03.
//
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
Node* generate(vector<int> arr,int start,int end){
    if(start > end) return NULL;
    int mid = start + (end-start)/2;
    Node *cur = new Node(arr[mid]);
    cur->left = generate(arr,start,mid-1);
    cur->right = generate(arr,mid+1,end);
    return cur;
}
Node* generateTree(vector<int> arr){
    return generate(arr,0,arr.size()-1);
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    Node* root = generateTree(arr);
    return 0;
}