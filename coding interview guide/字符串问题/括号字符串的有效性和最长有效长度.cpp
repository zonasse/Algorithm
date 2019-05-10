//
// Created by 钟奇龙 on 2019-05-10.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * 括号字符串的有效性
 */
bool isValid(string s){
    int status = 0;
    for(int i=0; i<s.size(); ++i){
        if(s[i] != '(' && s[i] != ')'){
            return false;
        }
        if(s[i] == ')' && --status < 0){
            return false;
        }
        if(s[i] == '('){
            status++;
        }
    }
    return status == 0;
}
/*
 * 括号字符串的最长有效长度
 */
int maxLength(string s){
    if(s.size() == 0) return 0;
    vector<int> dp(s.size(),0);
    int res = 0;
    for(int i=1; i<s.size(); ++i){
        if(s[i] == ')'){
            int pre = i - dp[i-1] - 1;
            if(pre >= 0 && s[pre] == '('){
                dp[i] = 2 + dp[i-1] + (dp[pre-1] > 0 ? dp[pre-1]:0);
            }
        }
        res = max(res,dp[i]);

    }
    return res;
}
int main(){
    string s = "()()(";
    cout<<isValid(s)<<endl;
    cout<<maxLength(s)<<endl;
    string s2 = "()(()()(";
    cout<<maxLength(s2)<<endl;

    return 0;
}