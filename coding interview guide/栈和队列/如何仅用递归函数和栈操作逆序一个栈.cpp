//
// Created by 钟奇龙 on 2019-04-12.
//
#include <stack>
using namespace std;

int getAndRemoveLastElement(stack<int> &s){
    int result = s.top();
    s.pop();
    if(s.empty()){
        return result;
    }else{
        int last = getAndRemoveLastElement(s);
        s.push(result);
        return last;
    }
}
void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int last = getAndRemoveLastElement(s);
    reverseStack(s);
    s.push(last);
}