#include <bits/stdc++.h>
using namespace std;

class MyQueue{
public:
    MyQueue(){
    }
    void push(int x){
        stack<int> temp_stack;
        while(_data.empty() == false){
            temp_stack.push(_data.top());
            _data.pop();
        }
        _data.push(x);
        while(temp_stack.empty() == false){
            _data.push(temp_stack.top());
            temp_stack.pop();
        }
    }
    int front(){
        return _data.top();
    }
    bool empty(){
        return _data.empty();
    }
    int pop(){
        int x = _data.top();
        _data.pop();
        return x;
    }
private:
    stack<int> _data;
};

int main(){

    return 0;
}
