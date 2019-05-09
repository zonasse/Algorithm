//
// Created by 钟奇龙 on 2019-05-09.
//

#include <iostream>
#include <string>
using namespace std;

int numSum(string s){
    if(s.size() == 0) return 0;
    int res = 0;
    int num = 0;
    int cur = 0;
    bool positive = true;
    for(int i=0; i<s.size(); ++i){
        int cur = s[i]-'0';
        if(cur < 0 || cur > 9){
            res += num;
            num = 0;
            if(s[i] == '-'){
                if( i > 0 && s[i-1] == '-'){
                    positive = !positive;
                }else{
                    positive = false;
                }
            }else{
                positive = true;
            }
        }else{
            num = num * 10 + (positive ? cur : -cur);
        }
    }
    res += num;
    return res;
}

int main(){
    cout<<numSum("A-1B--2C--D6E")<<endl;
}