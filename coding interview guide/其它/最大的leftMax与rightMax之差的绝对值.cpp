//
// Created by 钟奇龙 on 2019-05-18.
//
#include <iostream>
#include <vector>
using namespace std;

int maxABS(vector<int> arr){
    int maxValue = INT_MIN;
    for(int i=0; i<arr.size(); ++i){
        maxValue = max(maxValue,arr[i]);
    }
    return max(maxValue-arr[0],maxValue-arr[arr.size()-1]);
}

int main(){
    cout<<maxABS({2,7,3,1,1})<<endl;
    cout<<maxABS({7,1,1,9,8})<<endl;

    return 0;
}