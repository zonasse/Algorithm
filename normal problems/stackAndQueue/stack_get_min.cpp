#include <bits/stdc++.h>
using namespace std;

class MyStack{
public:
    MyStack(){
    }
    void push(int x){
        if(_min.empty() == true){
            _min.push(x);
        }else{
            if(x < _min.top()){
                _min.push(x);
            }else{
                _min.push(_min.top());
            }
        }
        _data.push(x);
    }
    int pop(){
        int x = _data.top();
        _data.pop();
        _min.pop();
        return x;
    }
    int top(){
        return _data.top();
    }
    int getMin(){
        return _min.top();
    }
    bool empty(){
        return _data.empty();
    }
private:
    stack<int> _data;
    stack<int> _min;
};
int main(){

    return 0;
}
