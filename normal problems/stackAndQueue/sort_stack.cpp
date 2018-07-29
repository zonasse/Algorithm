#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void sort_stack(stack<int> &s){
        stack<int> help;
        if(s.empty()){
            return;
        }
        while(s.empty() == false){
            int _top = s.top();
            s.pop();
            if(help.empty() == true || _top <= help.top()){
                help.push(_top);
            }else{
                while(help.empty() == false && help.top() < _top){
                    s.push(help.top());
                    help.pop();
                }
                help.push(_top);
            }
        }
        //将help中的所有元素倒入s
        while(help.empty() == false){
            s.push(help.top());
            help.pop();
        }
    }

};

int main(){
    stack<int> s;
    s.push(5);
    s.push(1);
    s.push(2);
    s.push(6);
    s.push(4);
    s.push(3);
    Solution test;
    test.sort_stack(s);
    while(s.empty() == false){
        printf("%d\n",s.top());
        s.pop();
    }
    return 0;
}
