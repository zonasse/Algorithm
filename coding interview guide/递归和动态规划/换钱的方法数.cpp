//
// Created by 钟奇龙 on 2019-05-05.
//
#include <iostream>
#include <vector>
using namespace std;
/*
 * 暴力递归
 */
int process1(vector<int> arr,int index,int aim){
    int res = 0;
    if(index == arr.size()){
        res =  aim == 0 ? 1:0;
    }else{
        for(int i=0; i * arr[index] <= aim; ++i){
            res += process1(arr,index+1,aim-arr[index]*i);
        }
    }
    return res;
}
int coins1(vector<int> arr,int aim){
    if(arr.size() == 0 || aim < 0) return 0;
    return process1(arr,0,aim);
}
/*
 * 暴力递归加记忆搜索
 */
int process2(vector<int> arr,int index,int aim,vector<vector<int> > &map){
    int res = 0;
    if(index == arr.size()){
        res = aim == 0 ? 1:0;
    }else{
        for(int i=0; i*arr[index] <= aim; ++i){
          int mapValue = map[index+1][aim-arr[index]*i];
          if(mapValue != 0){
              res += mapValue == -1 ? 0:mapValue;
          }else{
              res += process2(arr,index+1,aim-arr[index]*i,map);
          }
        }
    }
    map[index][aim] = res == 0 ? -1:res;
    return res;
}
int coins2(vector<int> arr,int aim){
    if(arr.size() == 0 || aim < 0) return 0;
    vector<vector<int> > map(arr.size()+1,vector<int> (aim+1));
    return process2(arr,0,aim,map);
}
int coins3(vector<int> arr,int aim){
    if(arr.size() == 0 || aim < 0) return 0;
    vector<vector<int> > dp(arr.size(),vector<int> (aim+1));
    for (int i = 0; i < arr.size(); ++i) {
        dp[i][0] = 1;
    }
    for(int j=1; j * arr[0] <= aim; ++j){
        dp[0][j*arr[0]] = 1;
    }
    for(int i=1; i<arr.size(); ++i){
        for(int j=1; j<=aim; ++j){
            int num=0;
            for(int k=0; j-arr[i]*k >= 0; ++k){
                num += dp[i-1][j-arr[i]*k];
            }
            dp[i][j] = num;
        }
    }
    return dp[arr.size()-1][aim];
}
/*
 * 最优解
 */
int coins4(vector<int> arr,int aim){
    if(arr.size() == 0 || aim < 0) return 0;
    vector<vector<int> > dp(arr.size(),vector<int> (aim+1));
    for(int i=0; i<arr.size(); ++i){
        dp[i][0] = 1;
    }
    for(int j=1; j*arr[0] <= aim; ++j){
        dp[0][j*arr[0]] = 1;
    }
    for(int i=1; i<arr.size(); ++i){
        for(int j=1; j<=aim; ++j){
            dp[i][j] = dp[i-1][j];
            dp[i][j] += j-arr[i] >= 0 ? dp[i][j-arr[i]] : 0;
        }
    }
    return dp[arr.size()-1][aim];
}
int coins5(vector<int> arr,int aim){
    if(arr.size() == 0 || aim < 0) return 0;
    vector<int> dp(aim+1);
    for(int j=0; j * arr[0] <= aim; ++j){
        dp[j*arr[0]] = 1;
    }
    for(int i=1; i<arr.size(); ++i){
        for(int j=1; j<=aim; ++j){
            dp[j] = (j-arr[i] >=0 ? dp[j-arr[i]]:0) + dp[j];
        }
    }
    return dp[aim];
}
int main(){
    vector<int> arr = {5,10,25,1};
    cout<<coins1(arr,15)<<endl;
    cout<<coins2(arr,15)<<endl;
    cout<<coins3(arr,15)<<endl;
    cout<<coins4(arr,15)<<endl;
    cout<<coins5(arr,15)<<endl;

    return 0;
}