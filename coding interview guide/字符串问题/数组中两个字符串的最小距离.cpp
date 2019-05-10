//
// Created by 钟奇龙 on 2019-05-10.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int minDistance(vector<string> strs,string s1,string s2){
    if(strs.size() == 0) return -1;
    if(s1 == s2) return 0;
    int last1 = -1;
    int last2 = -1;
    int minDis = INT_MAX;
    for(int i=0; i<strs.size(); ++i){
        if(strs[i] == s1){
            minDis = min(minDis,last2 == -1 ? minDis:i-last2);
            last1 = i;
        }else if(strs[i] == s2){
            minDis = min(minDis,last1 == -1 ? minDis:i-last1);
            last2 = i;
        }
    }
    return minDis == INT_MAX ? -1:minDis;
}


int main(){
    vector<string> strs = {"1","3","3","3","2","3","1"};
    cout<<minDistance(strs,"1","2")<<endl;

    return 0;
}