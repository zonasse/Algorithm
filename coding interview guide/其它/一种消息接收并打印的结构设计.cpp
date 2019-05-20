//
// Created by 钟奇龙 on 2019-05-20.
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Node{
public:
    int value;
    Node *next;
    Node(int x):value(x),next(NULL){

    }
};
class MessageBox{
private:
    map<int,Node*> headMap;
    map<int,Node*> tailMap;
    int lastPrint;
public:
    MessageBox(){
        this->lastPrint = 0;
    }
    void receive(int num){
        Node *cur = new Node(num);
        this->headMap[num] = cur;
        this->tailMap[num] = cur;
        if(this->tailMap.find(num-1) != this->tailMap.end()){
            this->tailMap[num-1]->next = cur;
            this->tailMap.erase(this->tailMap.find(num-1));
            this->headMap.erase(this->headMap.find(num));
        }
        if(this->headMap.find(num+1) != this->headMap.end()){
            cur->next = this->headMap[num+1];
            this->tailMap.erase(this->tailMap.find(num));
            this->headMap.erase(this->headMap.find(num+1));
        }
        if(this->headMap.find(lastPrint+1) != this->headMap.end()){
            print();
        }
    }
    void print(){
        Node *node = this->headMap[this->lastPrint+1];
        this->headMap.erase(this->headMap.find(this->lastPrint+1));
        while(node){
            cout<<node->value<<" ";
            node = node->next;
            lastPrint++;
        }
        this->tailMap.erase(this->tailMap.find(lastPrint));
        cout<<endl;
    }
};

int main(){
    vector<int> message = {2,1,4,5,7,3,9,8,6};
    MessageBox *box = new MessageBox();
    for(int num:message){
        box->receive(num);
    }
    return 0;
}