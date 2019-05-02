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
string serialTree(Node *root){
    if(!root) return "!#";
    string res = to_string(root->data) + "!";
    res += serialTree(root->left);
    res += serialTree(root->right);
    return res;
}
vector<int> getNextArr(string m){
    if(m.size() == 1){
        return {-1};
    }
    vector<int> nextArr(m.size());
    nextArr[0] = -1;
    nextArr[1] = 0;
    int cnt = 0;
    int pos = 2;
    while(pos < m.size()){
        if(m[pos-1] == m[cnt]){
            nextArr[pos] = ++cnt;
            pos++;
        }else if(cnt > 0){
            cnt = nextArr[cnt];
        }else{
            nextArr[pos] = 0;
        }
    }
    return nextArr;
}
int getIndexOf(string s,string m){
    if(m.size() == 0 || s.size() < m.size()){
        return -1;
    }
    int si = 0;
    int mi = 0;
    vector<int> nextArr = getNextArr(m);
    while(si < s.size() && mi < m.size()){
        if(s[si] == m[mi]){
            si++;
            mi++;
        }else if(nextArr[mi] == -1){
            si++;
        }else{
            mi = nextArr[mi];
        }
    }
    return mi == m.size() ? (si-mi) : -1;

}
//主方法
bool isSubTree(Node *t1,Node *t2){
    string s1 = serialTree(t1);
    string s2 = serialTree(t2);
    return getIndexOf(s1,s2) != -1;
}