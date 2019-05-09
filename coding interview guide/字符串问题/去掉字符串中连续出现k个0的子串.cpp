//
// Created by 钟奇龙 on 2019-05-09.
//

#include <iostream>
#include <string>
using namespace std;

string removeKZeros(string s,int k){
    if(s.size() < k) return s;
    int count = 0;
    int start = -1;
    int i=0;
    while(i < s.size()){
        if(s[i] == '0'){
            count++;
            start = start == -1 ? i:start;
            i++;
        }else{
            if(count == k){
                s.erase(start,count);
                i -= count;
            }else{
                i++;
            }
            start = -1;
            count = 0;
        }
    }
    if(count == k){
        s.erase(start,count);
    }
    return s;
}
int main(){
    string s = "0000d000k000040000";
    cout<<removeKZeros(s,4)<<endl;
    cout<<s<<endl;


    return 0;
}