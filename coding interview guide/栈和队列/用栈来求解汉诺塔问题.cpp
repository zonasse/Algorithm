//
// Created by 钟奇龙 on 2019-04-14.
//

#include <stack>
#include <string>
#include <iostream>
using namespace std;

enum Action{
    No,
    LToM,
    MToL,
    MToR,
    RToM
};
int fromStackToStack(Action &lastState,Action preNoAct,Action nowAct,stack<int> &fStack,stack<int> &tStack,string from,string to){
    if(lastState != preNoAct && fStack.top() < tStack.top()){
        tStack.push(fStack.top());
        fStack.pop();
        lastState = nowAct;
        cout<<"move "<<tStack.top()<<" from "<<from<<" to "<<to<<endl;
        return 1;
    }
    return 0;
}
int hanoiProblem(int num){
    stack<int> lS;
    stack<int> mS;
    stack<int> rS;
    lS.push(INT_MAX);
    mS.push(INT_MAX);
    rS.push(INT_MAX);
    string left = "left";
    string mid = "mid";
    string right = "right";
    for (int i = num; i > 0; --i) {
        lS.push(i);
    }
    Action state = No;
    int step = 0;
    while(rS.size() != num+1){
        step += fromStackToStack(state,MToL,LToM,lS,mS,left,mid);
        step += fromStackToStack(state,LToM,MToL,mS,lS,mid,left);
        step += fromStackToStack(state,RToM,MToR,mS,rS,mid,right);
        step += fromStackToStack(state,MToR,RToM,rS,mS,right,mid);
    }
    return step;

}

int main(){
    cout<<"total step is "<<hanoiProblem(9)<<endl;
}