//
// Created by 钟奇龙 on 2019-05-02.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL){}
};
bool isPost(vector<int> arr,int start,int end){
    if(start == end) return true;
    int less = -1;
    int more = end;
    for(int i=start; i<end; ++i){
        if(arr[i] < arr[end]){
            less = i;
        }else{
            more = more == end ? i : more;
        }
    }
    if(less == -1 || more == end){
        return isPost(arr,start,end-1);
    }
    if(less != more-1) return false;
    return isPost(arr,start,less) && isPost(arr,more,end-1);
}
bool isPostArray(vector<int> arr){
    if(arr.size() == 0){
        return false;
    }
    return isPost(arr,0,arr.size()-1);
}



Node* postToBST(vector<int> &arr,int start, int end){
    if(start > end) return NULL;
    int less = -1;
    int more = end;
    Node *head = new Node(arr[end]);
    for(int i=0; i<end; ++i){
        if(arr[i] < arr[end]){
            less = i;
        }else{
            more = more == end ? i : more;
        }
    }
    head->left = postToBST(arr,start,less);
    head->right = postToBST(arr,more,end-1);
    return head;
}
Node* postArrayToBST(vector<int> arr){
    if(arr.size() == 0) return NULL;
    return postToBST(arr,0,arr.size()-1);
}