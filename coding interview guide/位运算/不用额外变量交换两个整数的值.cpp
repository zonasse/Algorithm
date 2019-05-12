//
// Created by 钟奇龙 on 2019-05-12.
//
#include <iostream>
using namespace std;
void swap(int &a,int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}

int main(){
    int a = 5;
    int b = 0;
    swap(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;
}