//
// Created by 钟奇龙 on 2019-04-12.
//
#include <iostream>
#include <stack>
#include <exception>
using namespace std;

class MyQueue{
public:
    void push(int newNum){
        push_stack.push(newNum);
    }
    int front(){
        if(push_stack.empty() && pop_stack.empty()) {
            throw runtime_error("your queue is empty");
        }else if(pop_stack.empty()){
            while(push_stack.empty() == false){
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
        }
        return pop_stack.top();
    }
    int pop(){
        if(push_stack.empty() && pop_stack.empty()){
            throw runtime_error("your queue is empty");
        }else if(pop_stack.empty()){
            while(push_stack.empty() == false){
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
        }
        int num = pop_stack.top();
        pop_stack.pop();
        return num;
    }
private:
    stack<int> push_stack;
    stack<int> pop_stack;
};
