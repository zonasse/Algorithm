//
// Created by 钟奇龙 on 2019-05-11.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int minLength(string s1,string s2){
    if(s1.size() < s2.size()) return 0;
    vector<int> mark(256,0);
    for(int i=0; i<s2.size(); ++i){
        mark[s2[i]]++;
    }
    int res = INT_MAX;
    int match = s2.size();
    int left = 0;
    int right = 0;
    while(right < s1.size()){
        mark[s1[right]]--;
        if(mark[s1[right]] >= 0){
            match--;
        }
        if(match == 0){
            while(mark[s1[left]] < 0){
                mark[s1[left++]]++;
            }
            res = min(res,right-left+1);
            mark[s1[left++]]++;
            match++;
        }
        right++;
    }
    return res == INT_MAX ? 0:res;
}

int main(){
    cout<<minLength("abcde","ac")<<endl;
    cout<<minLength("12345","344")<<endl;

    return 0;
}