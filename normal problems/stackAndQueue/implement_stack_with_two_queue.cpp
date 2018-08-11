/*
 *  用两个队列实现栈
 */
#include <bits/stdc++.h>
using namespace std;

class MyStack{
public:
    MyStack(){}
    void push(int x){
        queue<int> tempQueue;
        tempQueue.push(x);
        while(_data.empty() == false){
            tempQueue.push(_data.front());
            _data.pop();
        }
        while(tempQueue.empty() == false){
            _data.push(tempQueue.front());
            tempQueue.pop();
        }
    }
    int pop(){
        int x = _data.front();
        _data.pop();
        return x;
    }
    int top(){
        return _data.front();
    }
    bool isEmpty(){
        return _data.empty();
    }
private:
    queue<int> _data;
};

int main(){
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    printf("%d\n",s.top());
    s.pop();
    printf("%d\n",s.top());
    s.push(5);
    printf("%d\n",s.top());
    return 0;
}
