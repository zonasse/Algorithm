//
// Created by 钟奇龙 on 2019-05-10.
//
#include <iostream>
#include <string>
using namespace std;
void reverseWord(string &s,int left,int right){
    while(left < right){
        swap(s[left++],s[right--]);
    }
}
/*
 * 单词顺序逆序
 */
void rotateWord(string &s){
    if(s.size() == 0) return;
    int left = -1;
    int right = -1;
    reverseWord(s,0,s.size()-1);
    for(int i=0; i<s.size(); ++i){
        if(s[i] != ' '){
            left = i == 0 || (s[i-1] == ' ') ? i : left;
            right = i == s.size()-1 || s[i+1] == ' ' ? i : right;
        }
        if(left != -1 && right != -1){
            reverseWord(s,left,right);
            left = -1;
            right = -1;
        }
    }
}
/*
 * 数组部分逆序
 */
void rotateWord2(string &s,int size){
    if(s.size() == 0 || s.size() < size) return;
    reverseWord(s,0,size-1);
    reverseWord(s,size,s.size()-1);
    reverseWord(s,0,s.size()-1);
}
int main(){
    string s = "dog loves pig";
    string s1 = "i'm a student";
    rotateWord(s);
    cout<<s<<endl;
    string s2 = "abcde";
    rotateWord2(s2,3);
    cout<<s2<<endl;
    return 0;
}