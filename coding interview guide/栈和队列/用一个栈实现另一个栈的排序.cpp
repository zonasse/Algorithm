//
// Created by 钟奇龙 on 2019-04-14.
//
#include <stack>
using namespace std;

void sortStackByStack(stack<int> &s){
    stack<int> help;
    while(s.empty() == false){
        int cur = s.top();
        s.pop();
        while(help.empty() == false && cur > help.top()){
            s.push(help.top());
            help.pop();
        }
        help.push(cur);
    }
    while(help.empty() == false){
        s.push(help.top());
        help.pop();
    }
}