//
// Created by 钟奇龙 on 2019-05-18.
//
#include <iostream>
#include <map>

using namespace std;

class Node{
public:
    Node *front;
    Node *next;
    int value;
    Node(int x):value(x),front(NULL),next(NULL){

    }
};

class NodeDoubleLinkedList{
private:
    Node *head;
    Node *tail;
public:
    NodeDoubleLinkedList():head(NULL),tail(NULL){

    }
    void addNode(Node *newNode){
        if(!newNode) return;
        if(this->head == NULL){
            this->head = newNode;
            this->tail = newNode;
        }else{
            this->tail->next = newNode;
            newNode->front = this->tail;
            this->tail = newNode;
        }
    }
    Node* deleteHead(){
        if(this->head == NULL) return NULL;
        Node *res = this->head;
        if(this->head == this->tail){
            this->head = NULL;
            this->tail = NULL;
        }else{
            this->head = res->next;
            this->head->front = NULL;
            res->next = NULL;
        }
        return res;
    }
    void moveNodeToTail(Node *node){
        if(!node) return;
        if(this->tail == node) return;
        if(this->head == node){
            this->head = node->next;
            this->head->front = NULL;
        }else{
            node->front->next = node->next;
            node->next->front = node->front;
        }
        this->tail->next = node;
        node->front = this->tail;
        node->next = NULL;
        this->tail = node;
    }
};

class MyCache{
private:
    map<int,Node*> keyNodeMap;
    map<Node*,int> nodeKeyMap;
    NodeDoubleLinkedList *nodeList;
    int capacity;
public:
    MyCache(int capacity){
        if(capacity < 1){
            cout<<"capacity should greater than 0";
        }
        this->capacity = capacity;
        this->nodeList = new NodeDoubleLinkedList();
    }
    int get(int key){
        if(this->keyNodeMap.find(key) != this->keyNodeMap.end()){
            Node *node = keyNodeMap[key];
            this->nodeList->moveNodeToTail(node);
            return node->value;
        }else{
            return INT_MIN;
        }
    }
    void set(int key,int value){
        if(this->keyNodeMap.find(key) != this->keyNodeMap.end()){
            Node *node = keyNodeMap[key];
            node->value = value;
            this->nodeList->moveNodeToTail(node);
        }else{
            Node *newNode = new Node(value);
            this->keyNodeMap[key] = newNode;
            this->nodeKeyMap[newNode] = key;
            this->nodeList->addNode(newNode);
            if(this->keyNodeMap.size() == this->capacity + 1){
                Node *deleteNode = this->nodeList->deleteHead();
                int deleteKey = this->nodeKeyMap[deleteNode];
                this->keyNodeMap.erase(this->keyNodeMap.find(deleteKey));
                this->nodeKeyMap.erase(this->nodeKeyMap.find(deleteNode));

            }
        }
    }
};

int main(){
    MyCache *cache = new MyCache(3);
    cache->set('A',1);
    cache->set('B',2);
    cache->set('C',3);
    cout<<cache->get('A')<<endl;
    cache->set('D',4);
    return 0;
}