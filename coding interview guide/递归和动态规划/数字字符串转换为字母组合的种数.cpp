//
// Created by 钟奇龙 on 2019-05-06.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int helper(string str,int index){
    if(index == str.size()) return 1;
    if(str[index] == '0') return 0;
    int res = 0;
    res += helper(str,index+1);
    if(index+1 < str.size() && (str[index]-'0')*10 + (str[index+1]-'0') < 27){
        res += helper(str,index+2);
    }
    return res;

}
int num1(string str){
    if(str.size() == 0) return 0;
    return helper(str,0);
}

int num2(string str){
    if(str.size() == 0) return 0;
    int cur = str[str.size()-1] == '0' ? 0:1;
    int next = 1;
    int temp = 0;
    for(int i=str.size()-2; i>=0; --i){
        if(str[i] == '0'){
            next = cur;
            cur = 0;
        }else{
            temp = cur;
            if((str[i]-'0') * 10 + (str[i+1]-'0') < 27){
                cur += next;
            }
            next = temp;
        }
    }
    return cur;
}

int main(){
    string str = "1111";
    cout<<num1(str)<<endl;
    cout<<num2(str)<<endl;

    return 0;
}