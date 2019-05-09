//
// Created by 钟奇龙 on 2019-05-09.
//

#include <iostream>
#include <string>
using namespace std;

bool isDeformation(string s1, string s2){
    if(s1.size() != s2.size()) return false;
    int mark[256];
    memset(mark, 0,sizeof(mark));
    for(int i=0; i<s1.size(); ++i){
        mark[s1[i]]++;
    }
    for(int j=0; j<s2.size(); ++j){
        if(mark[s2[j]]-- == 0) return false;
    }
    return true;

}

int main(){
    cout<<isDeformation("123","312")<<endl;

    return 0;
}

