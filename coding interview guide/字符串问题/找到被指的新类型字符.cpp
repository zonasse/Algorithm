//
// Created by 钟奇龙 on 2019-05-11.
//
#include <iostream>
#include <string>
using namespace std;

string pointNewchar(string s,int k){
    if(s.size() == 0 || k < 0 || s.size() <= k){
        return "";
    }
    int num = 0;
    for(int i=k-1; i>=0; --i){
        if(isupper(s[i])){
            num++;
        }else{
            break;
        }
    }
    if((num & 1) == 1){
        return s.substr(k-1,2);
    }
    if(isupper(s[k])){
        return s.substr(k,2);
    }
    return s.substr(k,1);
}

int main(){
    string s = "aaABCDEcBCg";
    cout<<pointNewchar(s,7)<<endl;
    cout<<pointNewchar(s,4)<<endl;
    cout<<pointNewchar(s,10)<<endl;

    return 0;
}