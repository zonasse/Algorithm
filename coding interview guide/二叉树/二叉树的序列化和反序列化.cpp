//
// Created by 钟奇龙 on 2019-05-01.
//
#include <iostream>
#include <string>
#include <queue>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL){}
};

string serialByPreOrder(Node *root){
    if(!root) return "#!";
    string res = to_string(root->data) + "!";
    res += serialByPreOrder(root->left);
    res += serialByPreOrder(root->right);
    return res;
}

vector<string> split(const string& str, const string& pattern) {
    vector<string> ret;
    if (pattern.empty()) return ret;
    size_t start = 0, index = str.find_first_of(pattern, 0);
    while (index != str.npos) {
        if (start != index)
            ret.push_back(str.substr(start, index - start));
        start = index + 1;
        index = str.find_first_of(pattern, start);
    }
    if (!str.substr(start).empty())
        ret.push_back(str.substr(start));
    return ret;
}
Node* reconByPre(queue<string> &str_queue){
    if(str_queue.empty()) return NULL;
    string cur = str_queue.front();
    str_queue.pop();
    if(cur == "#") return NULL;
    Node *node = new Node(stoi(cur));
    node->left = reconByPre(str_queue);
    node->right = reconByPre(str_queue);
    return node;
}
Node* reconByPreString(string preStr){
    vector<string> values(split(preStr,"!"));
    queue<string> str_queue;
    for(int i=0; i<values.size(); ++i){
        str_queue.push(values[i]);
    }
    return reconByPre(str_queue);
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
    string serial = serialByPreOrder(node1);
    cout<<serial<<endl;
    Node *res = reconByPreString(serial);

    return 0;
}