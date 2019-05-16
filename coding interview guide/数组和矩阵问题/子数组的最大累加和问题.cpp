//
// Created by 钟奇龙 on 2019-05-16.
//
#include <iostream>
#include <vector>
using namespace std;
int maxSum(vector<int> arr){
    if(arr.size() == 0) return 0;
    int curSum = 0;
    int maxSum = 0;
    for(int i=0; i<arr.size(); ++i){
        curSum += arr[i];
        maxSum = max(maxSum,curSum);
        if(curSum < 0){
            curSum = 0;
        }
    }
    return maxSum;
}

int main(){
    vector<int> arr = {1,-2,3,5,-2,6,-1};
    cout<<maxSum(arr)<<endl;
    return 0;
}
