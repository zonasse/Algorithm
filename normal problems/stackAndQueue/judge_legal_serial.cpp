#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool judge_legal_serial(queue<int> &order){
        int n = order.size();
        stack<int> s;
        for(int i=1; i<=n; ++i){
            s.push(i);
            while(s.empty() == false && s.top() == order.front()){
                order.pop();
                s.pop();
            }
        }
        if(s.empty() == false){
            return false;
        }
        return true;
    }

};

int main(){

    return 0;
}
