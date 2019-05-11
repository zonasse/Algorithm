//
// Created by 钟奇龙 on 2019-05-11.
//

#include <string>
#include <iostream>
using namespace std;
bool isValid(string str,string express){
    for(int i=0; i<str.size(); ++i){
        if(str[i] == '.' || str[i] == '*') return false;
    }
    for(int i=0; i<express.size(); ++i){
        if(express[i] == '*' && (i == 0 || express[i-1] == '*')){
            return false;
        }
    }
    return true;
}
bool process(string str,int si,string express,int ei){
    if(ei == express.size()){
        return si == str.size();
    }
    //必须比较str[si]和express[ei]时
    if(ei == express.size()-1 ||  express[ei+1] != '*'){
        return si < str.size() && (str[si] == express[ei] || express[ei] == '.') && process(str,si+1,express,ei+1);
    }
    //express[ei+1]为*时
    while(si < str.size() && (str[si] == express[ei] || express[ei] == '.')){
        if(process(str,si,express,ei+2)){
            return true;
        }
        si++;
    }
    //si已到末尾或str[si]与express[ei]不相等时
    return process(str,si,express,ei+2);
}
/*
 * 主函数
 */
bool isMatch(string str,string express){
    return isValid(str,express) && process(str,0,express,0);
}

int main(){
    cout<<isMatch("abcd","a.cd*")<<endl;

    return 0;
}