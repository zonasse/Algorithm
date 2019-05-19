//
// Created by 钟奇龙 on 2019-05-19.
//
#include <iostream>
using namespace std;

bool isPalindrome(int n){
    if(n == INT_MIN) return false;
    n = abs(n);
    int help = 1;
    while(n / help >= 10){
        help *= 10;
    }
    while(n){
        if(n / help != n % 10){
            return false;
        }
        n = (n%help)/10;
        help /= 100;
    }
    return true;
}

int main(){
    cout<<isPalindrome(1221)<<endl;

    return 0;
}