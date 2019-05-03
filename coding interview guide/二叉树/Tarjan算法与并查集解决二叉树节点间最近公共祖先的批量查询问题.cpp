//
// Created by 钟奇龙 on 2019-05-03.
//


#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL){}
};

class Query{
public:
    Node* o1;
    Node *o2;
    Query():o1(NULL),o2(NULL){}
};
class DisjointSets{
public:
    map<Node*,Node*> fatherMap;
    map<Node*,int> rankMap;

    void makeSets(Node* root){
        this->fatherMap.clear();
        this->rankMap.clear();
        preOrderMake(root);
    }
    void preOrderMake(Node* root){
        if(!root) return;
        fatherMap[root] = root;
        rankMap[root] = 0;
        preOrderMake(root->left);
        preOrderMake((root->right));
    }
    Node* findFather(Node *node){
        Node *father = fatherMap[node];
        if(father != node){
            father = findFather(father);
        }
        fatherMap[node] = father;
        return father;
    }
    void unionTwoNodes(Node *node1,Node *node2){
        if(!node1 || !node2) return;
        Node *father1 = findFather(node1);
        Node *father2 = findFather(node2);
        if(father1 != father2){
            int rank1 = rankMap[father1];
            int rank2 = rankMap[father2];
            if(rank1 < rank2){
                fatherMap[father1] = father2;
            }else if(rank1 > rank2){
                fatherMap[father2] = father1;
            }else{
                fatherMap[father2] = father1;
                rankMap[father1] = rank1 + 1;
            }
        }
    }
};

class Tarjan{
private:
    map<Node*,vector<Node*> > queryMap;
    map<Node*,vector<int> > indexMap;
    map<Node*,Node*> ancestorMap;
    DisjointSets sets;
public:
    vector<Node*> query(Node* head, vector<Query*> quries){
        vector<Node* > ans(quries.size());
        setQuries(quries,ans);
        sets.makeSets(head);
        setAnswers(head,ans);
        return ans;
    }
    void setQuries(vector<Query*> quries,vector<Node*> &ans){
        Node* o1 = NULL;
        Node* o2 = NULL;
        for(int i=0; i<ans.size(); ++i){
            o1 = quries[i]->o1;
            o2 = quries[i]->o2;
            if(o1 == o2 || !o1 || !o2){
                ans[i] = o1 == NULL ? o2 : o1;
            }else{
                if(queryMap.find(o1) == queryMap.end()){
                    queryMap[o1] = vector<Node*> ();
                    indexMap[o1] = vector<int> ();
                }
                if(queryMap.find(o2) == queryMap.end()){
                    queryMap[o2] = vector<Node*> ();
                    indexMap[o2] = vector<int> ();
                }
                queryMap[o1].push_back(o2);
                indexMap[o1].push_back(i);
                queryMap[o2].push_back(o1);
                indexMap[o2].push_back(i);
            }
        }
    }
    void setAnswers(Node *head, vector<Node*> &ans){
        if(!head) return;
        setAnswers(head->left,ans);
        sets.unionTwoNodes(head->left,head);
        ancestorMap[sets.findFather(head)] = head;

        setAnswers(head->right,ans);
        sets.unionTwoNodes(head->right,head);
        ancestorMap[sets.findFather(head)] = head;

        vector<Node*> nodeArr = queryMap[head];
        vector<int> indexArr = indexMap[head];
        for(int i=0; i<nodeArr.size(); ++i){
            Node *curNode = nodeArr[i];
            int index = indexArr[i];
            Node *nodeFather = sets.findFather(curNode);
            if(ancestorMap.find(nodeFather) != ancestorMap.end()){
                ans[index] = ancestorMap[nodeFather];
            }
        }
    }
};

//主方法
vector<Node*> tarJanQuery(Node *head,vector<Query*> quries){
    vector<Node*> ans = Tarjan().query(head,quries);
    return ans;
}

