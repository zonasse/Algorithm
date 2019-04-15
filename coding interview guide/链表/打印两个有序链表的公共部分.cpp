//
// Created by 钟奇龙 on 2019-04-15.
//
#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int x):data(x),next(NULL){

    }
};

void printCommonPart(Node *head1,Node *head2){
    cout<<"common part is"<<endl;
    while(head1 && head2){
        if(head1->data == head2->data){
            cout<<head1->data<<endl;
            head1 = head1->next;
            head2 = head2->next;
        }else if(head1->data < head2->data){
            head1 = head1->next;
        }else{
            head2 = head2->next;
        }
    }
}

int main(){

    return 0;
}