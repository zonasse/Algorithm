//
// Created by 钟奇龙 on 2019-05-18.
//
#include <iostream>
using namespace std;

/*
 * 原问题
 */
int zeroNum1(int num){
    if(num < 0) return 0;
    int res = 0;
    for(int i=5; i<=num; i+=5){
        int cur = i;
        while(cur % 5 == 0){
            res++;
            cur/=5;
        }
    }
    return res;
}
int zeroNum2(int num){
    if(num < 0) return 0;
    int res = 0;
    while(num != 0){
        res += num / 5;
        num /= 5;
    }
    return res;
}
/*
 * 进阶问题
 */
int rightOne(int num){
    if(num < 1) return -1;
    int res = 0;
    while(num != 0){
        res += (num >> 1);
        num >>= 1;
    }
    return res;
}
int main(){
//    cout<<zeroNum1(50)<<endl;
//    cout<<zeroNum2(1000000000)<<endl;
    cout<<rightOne(1000000000)<<endl;
    return 0;
}