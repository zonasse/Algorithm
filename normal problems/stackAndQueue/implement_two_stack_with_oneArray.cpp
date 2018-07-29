//一个数组实现两个栈
#include <bits/stdc++.h>
using namespace std;
const int maxsize = 1e3;

class doubleStack{
public:
    doubleStack(){
    }
    void initial(){
        _top1 = -1;
        _top2 = maxsize;
    }
    void push(int x,int tag){
        if(_top1 + 1 == _top2){
            printf("stack is full");
            return;
        }
        //tag为1时推入左栈，为0时推入右栈
        if(tag == 1){
            _data[++_top1] = x;
        }else{
            _data[--_top2] = x;
        }
    }
    int pop(int tag){
        //tag为1时弹出左栈，为0时弹出右栈
        if(tag == 1 && _top1 == -1){
            printf("the left stack is empty");
            return -1;
        }
        if(tag == 0 && _top2 == maxsize){
            printf("the right stack is empty");
            return -1;
        }
        if(tag == 1){
            return _data[_top1--];
        }
        if(tag == 0){
            return _data[_top2++];
        }
    }
    bool isEmpty(int tag){
        if(tag == 1 && _top1 == -1){
            return true;
        }
        if(tag == 2 && _top2 == maxsize){
            return true;
        }
        return false;
    }
private:
    int _top1;
    int _top2;
    int _data[maxsize];
};

int main(){
    doubleStack s;
    s.initial();
    s.push(1,1);
    s.push(2,0);
    s.push(4,1);
    s.pop(1);
    s.pop(1);
    s.pop(1);
    printf("\n%d\n",s.isEmpty(1));
    return 0;
}
