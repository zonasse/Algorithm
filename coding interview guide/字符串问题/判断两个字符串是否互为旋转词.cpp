//
// Created by 钟奇龙 on 2019-05-09.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> getNextArr(string pattern){
    if(pattern.size() == 0) return {};
    vector<int> nextArr(pattern.size());
    nextArr[0] = -1;
    nextArr[1] = 0;
    int cnt = 0;
    int pos = 2;
    while(pos < pattern.size()){
        if(pattern[pos-1] == pattern[cnt]){
            nextArr[pos++] = ++cnt;
        }else if(cnt > 0){
            cnt = nextArr[cnt];
        }else{
            nextArr[pos++] = 0;
        }
    }
    return nextArr;
}
int getIndexOf(string main,string pattern){
    if(main.size() == 0 || pattern.size() == 0 || main.size() < pattern.size()){
        return -1;
    }
    vector<int> nextArr = getNextArr(pattern);
    int mi = 0;
    int pi = 0;
    while(mi < main.size() && pi < pattern.size()){
        if(main[mi] == pattern[pi]){
            mi++;
            pi++;
        }else if(nextArr[pi] != -1){
            pi = nextArr[pi];
        }else{
            mi++;
        }
    }
    return pi == pattern.size() ? (mi-pi):-1;

}
bool judgeRotate(string s1,string s2){
    if(s1.size() != s2.size()) return false;
    s2 += s2;
    return getIndexOf(s2,s1) != -1;
}

int main(){
    cout<<judgeRotate("cdab","abcd")<<endl;

    return 0;
}