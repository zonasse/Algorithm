#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void reverse_stack(stack<int> &s){
        _reverse(s);
    }
private:
    void _reverse(stack<int> &s){
        if(s.empty()){
            return;
        }
        int top = s.top();
        s.pop();
        _reverse(s);
        s.push(top);
    }

};

int main(){
    stack<int> s;
    for(int i=1; i<=6; ++i){
        s.push(i);
    }
    Solution test;
    test.reverse_stack(s);
    while(s.empty() == false){
        printf("%d\n",s.top());
        s.pop();
    }
    return 0;
}
