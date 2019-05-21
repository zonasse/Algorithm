//
// Created by 钟奇龙 on 2019-05-21.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string manacherString(string str){
    int targetLength = 2 * str.size() + 1;
    string manacher = "";
    for(int i=0; i<targetLength; ++i){
        if(i % 2 == 0){
            manacher.push_back('#');
        }else{
            manacher.push_back(str[(i-1)/2]);
        }
    }
    return manacher;
}
/*
 * 原问题
 */
int maxLcpsLength(string str){
    if(str.size() == 0) return 0;
    string manacher = manacherString(str);
    vector<int> pArr(manacher.size());
    int index = -1;
    int pR = -1;
    int maxLength = INT_MIN;
    for(int i=0; i<manacher.size(); ++i){
        pArr[i] = pR > i ? min(pArr[index-(i-index)],pR-1 - i + 1):1;
        while(i+pArr[i] < manacher.size() && i-pArr[i] >= 0){
            if(manacher[i+pArr[i]] == manacher[i-pArr[i]]){
                pArr[i]++;
            }else{
                break;
            }
        }
        if(i+pArr[i] > pR){
            pR = i+pArr[i];
            index = i;
        }
        maxLength = max(maxLength,pArr[i]);
    }
    return maxLength - 1;
}
/*
 * 进阶问题
 */
string shortestLcpString(string str){
    if(str.size() == 0) return 0;
    string manacher = manacherString(str);
    vector<int> pArr(manacher.size());
    int index = -1;
    int pR = -1;
    int maxContainsLength = -1;
    for(int i=0; i<manacher.size(); ++i){
        pArr[i] = pR > i ? min(pArr[index - (i-index)],pR-1 - i + 1) : 1;
        while(i + pArr[i] < manacher.size() && i - pArr[i] >= 0){
            if(manacher[i+pArr[i]] == manacher[i-pArr[i]]){
                pArr[i]++;
            }else{
                break;
            }
        }
        if(i+pArr[i] > pR){
            pR = i + pArr[i];
            index = i;
        }
        if(pR == manacher.size()){
            maxContainsLength = pArr[i]-1;
            break;
        }
    }
    string res = "";
    for(int i=str.size()-maxContainsLength-1; i>=0; --i){
        res.push_back(str[i]);
    }
    return res;
}
int main(){
    cout<<maxLcpsLength("abc1234321ab")<<endl;
    cout<<shortestLcpString("abc1234321ab")<<endl;
    cout<<shortestLcpString("abcd123321")<<endl;

    return 0;
}