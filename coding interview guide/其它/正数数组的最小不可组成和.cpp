//
// Created by 钟奇龙 on 2019-05-19.
//
#include <iostream>
#include <vector>
using namespace std;

int unformedSum(vector<int> arr){
    if(arr.size() == 0) return 1;
    int sum = 0;
    int minSum = INT_MAX;
    for(int i=0; i<arr.size(); ++i){
        sum += arr[i];
        minSum = min(minSum,arr[i]);
    }
    vector<bool> dp(sum+1);
    dp[0] = true;
    for(int i=0; i<arr.size(); ++i){
        for(int j=sum; j>=arr[i]; --j){
            dp[j] = dp[j-arr[i]] ? true:dp[j];
        }
    }
    for(int i=minSum; i<=sum; ++i){
        if(!dp[i]){
            return i;
        }
    }
    return sum+1;
}

int unformedSum2(vector<int> arr){
    if(arr.size() == 0) return 1;
    sort(arr.begin(),arr.end());
    int range = 0;
    for(int i=0; i<arr.size(); ++i){
        if(arr[i] > range+1){
            return range+1;
        }else{
            range += arr[i];
        }
    }
    return range+1;
}

int main(){
    cout<<unformedSum({3,2,5})<<endl;
    cout<<unformedSum({1,2,4})<<endl;
    cout<<unformedSum2({1,2,4})<<endl;
    return 0;
}