//
// Created by 钟奇龙 on 2019-05-11.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxUnique(string s){
    if(s.size() == 0) return 0;
    int pre = -1;
    int res = 0;
    vector<int> index_map(256,-1);
    for(int i=0; i<s.size(); ++i){
        pre = max(pre,index_map[s[i]]);
        res = max(res,i-pre);
        index_map[s[i]] = i;
    }
    return res;
}

int main(){
    cout<<maxUnique("aabcb")<<endl;
    cout<<maxUnique("abcd")<<endl;

    return 0;
}