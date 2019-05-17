//
// Created by 钟奇龙 on 2019-05-17.
//

#include <iostream>
using namespace std;
int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main(){
    cout<<gcd(20,8)<<endl;
    return 0;
}