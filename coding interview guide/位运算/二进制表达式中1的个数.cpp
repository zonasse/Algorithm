//
// Created by 钟奇龙 on 2019-05-12.
//

#include <iostream>
using namespace std;
int countOf1(int num){
    int res = 0;
    while(num){
        num &= (num-1);
        res++;
    }
    return res;
}

int main(){
    cout<<countOf1(5)<<endl;

    return 0;
}