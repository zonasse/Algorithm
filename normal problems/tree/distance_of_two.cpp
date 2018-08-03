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
    /*
    * 思路：设t1和t2的最近公共祖先为ancestor,则dis(t1,t2) = dis(root,t1)+dis(root,t2)-2*dis(root,ancestor)
    */
    int distance_of_two(tNode *root,tNode *t1,tNode *t2){
        if(!root || !t1 || !t2){
            return -1;
        }
        vector<tNode *> node_vec1;
        vector<tNode *> node_vec2;
        bool find1 = get_node_path(root,t1,node_vec1);
        bool find2 = get_node_path(root,t2,node_vec2);

        if(!find1 || !find2){
            return -1;
        }
        int ancestorIndex=0;
        while(ancestorIndex < node_vec1.size() && ancestorIndex < node_vec2.size()){
            if(node_vec1[ancestorIndex] != node_vec2[ancestorIndex]){
                break;
            }
            ancestorIndex++;
        }
        return node_vec1.size() + node_vec2.size() - 2*ancestorIndex;
    }
    bool get_node_path(tNode *root,tNode *target,vector<tNode*> &path){
        if(!root){
            return false;
        }
        path.push_back(root);
        if(root == target){
            return true;
        }
        bool find = get_node_path(root->left,target,path);
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
    tNode *n4 = new tNode(4);
    tNode *n5 = new tNode(5);
    tNode *n6 = new tNode(6);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n5->right = n6;
    Solution handle;
    printf("dis = %d\n",handle.distance_of_two(n1,n3,n6));

    return 0;
}
