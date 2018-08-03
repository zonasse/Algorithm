#include <bits/stdc++.h>
using namespace std;

struct tNode{
    tNode *left;
    tNode *right;
    int data;
    tNode(int x):data(x),left(NULL),right(NULL){}
};
class Solution{
public:
    //µ›πÈ
    bool judge(tNode *root1,tNode *root2){
        if(!root1 && !root2){
            return true;
        }
        if(!root1 || !root2){
            return false;
        }
        if(root1->data != root2->data){
            return false;
        }
        return judge(root1->left,root2->left) && judge(root1->right,root2->right);
    }

    //∑«µ›πÈ
    bool judge2(tNode *root1,tNode *root2){
        if(!root1 && !root2){
            return true;
        }
        if(!root1 || !root2){
            return false;
        }
        //œ»–Ú±È¿˙≈–∂œ
        stack<tNode*> node_stack1;
        stack<tNode*> node_stack2;
        node_stack1.push(root1);
        node_stack2.push(root2);
        while(!node_stack1.empty() && !node_stack2.empty()){
            tNode *node1 = node_stack1.top();
            tNode *node2 = node_stack2.top();
            node_stack1.pop();
            node_stack2.pop();
            if(!node1 && !node2){
                continue;
            }else if(node1 && node2 && node1->data == node2->data){
                node_stack1.push(node1->right);
                node_stack1.push(node1->left);
                node_stack2.push(node2->right);
                node_stack2.push(node2->left);
            }else{
                return false;
            }
        }
        return true;
    }
};

int main(){

    return 0;
}
