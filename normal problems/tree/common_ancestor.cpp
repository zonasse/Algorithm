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
    //递归方式
    tNode* common_ancestor(tNode *root,tNode *t1,tNode *t2){
        if(find_node(root->left,t1)){
            if(!find_node(root->left,t2)){
                return root;
            }else{
                return common_ancestor(root->left,t1,t2);
            }
        }else{
            if(find_node(root->left,t2)){
                return root;
            }else{
                return common_ancestor(root->right,t1,t2);
            }
        }
    }
    bool find_node(tNode *root,tNode *target){
        if(!root || !target){
            return false;
        }
        if(root == target){
            return true;
        }
        bool find = find_node(root->left,target);
        if(!find){
            find = find_node(root->right,target);
        }
        return find;
    }
    //非递归方式
    tNode* common_ancestor2(tNode *root,tNode *t1,tNode *t2){
        if(!root || !t1 || !t2){
            return NULL;
        }
        vector<tNode*> node_vec1;
        vector<tNode*> node_vec2;
        bool find1 = get_node_path(root,t1,node_vec1);
        bool find2 = get_node_path(root,t2,node_vec2);
        if(!find1 || !find2){
            return NULL;
        }
        int i=0;
        tNode *ancestor = NULL;
        while(i < node_vec1.size() && i < node_vec2.size()){
            if(node_vec1[i] == node_vec2[i]){
                ancestor = node_vec1[i];
            }else{
                break;
            }
            i++;
        }
        return ancestor;
    }
    bool get_node_path(tNode *root,tNode *target,vector<tNode*> &path){
        if(!root){
            return false;
        }
        path.push_back(root);
        if(root == target){
            return true;
        }
        bool find = false;
        find = get_node_path(root->left,target,path);
        if(!find){
            find = get_node_path(root->right,target,path);
        }
        if(!find){
            path.pop_back();
        }
        return find;
    }
};

int main(){
    tNode *n1 = new tNode(1);
    tNode *n2 = new tNode(2);
    tNode *n3 = new tNode(3);
    n1->left = n2;
    n1->right = n3;
    Solution handle;
    printf("%d\n",handle.common_ancestor2(n1,n2,n3)->data);
    return 0;
}
