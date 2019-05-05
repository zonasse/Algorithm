//
// Created by 钟奇龙 on 2019-05-05.
//
#include <iostream>
#include <string>
using namespace std;
void func(int n,string from, string mid,string to){
    if(n == 1){
        cout<<"from "<<from<<"  to "<<to<<endl;
    }else{
        func(n-1,from,to,mid);
        func(1,from,mid,to);
        func(n-1,mid,from,to);
    }
}
void hanoi(int n){
    func(n,"left","mid","right");
}

int main(){
    hanoi(5);
}
