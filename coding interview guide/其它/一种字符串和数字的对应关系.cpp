//
// Created by 钟奇龙 on 2019-05-19.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getStringByNumber(string chs,int num){
    if(chs.size() == 0 || num < 1) return "";
    int cur = 1;
    int base = chs.size();
    int len = 0;
    while(num >= cur){
        len++;
        num -= cur;
        cur *= base;
    }
    string res = "";
    int index = 0;
    do{
        cur /= base;
        int nCur = num / cur;
        res.push_back(chs[nCur]);
        num %= cur;
    }while(res.size() < len);
    return res;
}
int getNthFromChar(string chs,char ch){
    int index = -1;
    for(int i=0; i<chs.size(); ++i){
        if(chs[i] == ch){
            index = i+1;
            break;
        }
    }
    return index;
}
int getNumberFromString(string chs, string str){
    if(chs.size() == 0 || str.size() == 0) return 0;
    int base = chs.size();
    int cur = 1;
    int res = 0;
    for(int i=str.size()-1; i>=0; --i){
        res += getNthFromChar(chs,str[i])*cur;
        cur *= base;
    }
    return res;
}
int main(){
    cout<<getStringByNumber("ABC",72)<<endl;
    cout<<getNumberFromString("ABC","BABC")<<endl;
    return 0;
}