//
// Created by 钟奇龙 on 2019-05-21.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
 * 获取next数组
 */
vector<int> getNextArr(string ms){
    vector<int> nextArr(ms.size());
    nextArr[0] = -1;
    nextArr[1] = 0;
    int pos = 2;
    int cn = 0;
    while(pos < ms.size()){
        if(ms[pos-1] == ms[cn]){
            nextArr[pos++] = ++cn;
        }else if(cn > 0){
            cn = nextArr[cn];
        }else{
            nextArr[pos++] = 0;
        }
    }
    return nextArr;
}
/*
 * KMP入口函数，ss为主串，ms为匹配串
 */
int getIndexOf(string ss,string ms){
    if(ss.size() == 0 || ms.size() == 0 || ss.size() < ms.size()){
        return -1;
    }
    vector<int> nextArr = getNextArr(ms);
    int si = 0;
    int mi = 0;
    while(si < ss.size() && mi < ms.size()){
        if(ss[si] == ms[mi]){
            si++;
            mi++;
        }else if(nextArr[mi] != -1){
            mi = nextArr[mi];
        }else{
            si++;
        }
    }
    return mi == ms.size() ? si-mi:-1;
}

int main(){
    cout<<getIndexOf("acbc","bc")<<endl;
    cout<<getIndexOf("acbc","bcc")<<endl;

    return 0;
}