#include <bits/stdc++.h>
using namespace std;

struct tNode{
    int data;
    tNode *left;
    tNode *right;
    tNode(int x):data(x),left(NULL),right(NULL){}
};

class Solution{
public:
    bool judge_complete_tree(tNode *root){
        if(!root){
            return false;
        }
        queue<tNode*> node_queue;
        bool leafMode = false;
        bool ret = true;
        node_queue.push(root);
        while(node_queue.empty() == false){
            tNode *node = node_queue.front();
            node_queue.pop();
            if(node->right && !node->left){
                //有右无左
                ret =  false;
                break;
            }else if(node->left && !node->right){
                //有左无右
                if(leafMode){
                    ret =  false;
                    break;
                }else{
                    leafMode = true;
                }
            }else if(!node->left && !node->right){
                //叶子节点
                leafMode = true;
            }else{
                //左右都有
                if(leafMode){
                    ret = false;
                    break;
                }
                node_queue.push(node->left);
                node_queue.push(node->right);
            }

        }
        return ret;

    }



};
int main(){
    tNode *n1 = new tNode(1);
    tNode *n2 = new tNode(2);
    tNode *n3 = new tNode(3);
    tNode *n4 = new tNode(4);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->left = new tNode(5);
    Solution handle;
    printf("%d\n",handle.judge_complete_tree(n1));
    return 0;
}
