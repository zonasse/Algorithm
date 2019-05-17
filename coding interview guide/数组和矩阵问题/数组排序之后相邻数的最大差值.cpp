//
// Created by 钟奇龙 on 2019-05-17.
//
#include <iostream>
#include <vector>
using namespace std;

int maxGap(vector<int> arr){
    if(arr.size() < 2) return 0;
    vector<int> buckets(arr.size()+1);
    vector<int> mins(arr.size()+1);
    vector<int> maxs(arr.size()+1);
    vector<bool> hasNum(arr.size()+1,false);
    int maxValue = INT_MIN;
    int minValue = INT_MAX;
    for(int i=0; i<arr.size(); ++i){
        maxValue = max(maxValue,arr[i]);
        minValue = min(minValue,arr[i]);
    }
    if(maxValue == minValue) return 0;
    for(int i=0; i<arr.size(); ++i){
        int bid = (arr[i]-minValue) * arr.size() / (maxValue-minValue);
        maxs[bid] = hasNum[bid] ? max(maxs[bid],arr[i]) : arr[i];
        mins[bid] = hasNum[bid] ? min(mins[bid],arr[i]) : arr[i];
        hasNum[bid] = true;
    }
    //找到第一个不为空的桶
    int lastMax = 0;
    int i=0;
    while(i<=arr.size()){
        if(hasNum[i++]){
            lastMax = maxs[i-1];
            break;
        }
    }
    int res = 0;
    while(i <= arr.size()){
        if(hasNum[i]){
            res = max(res,mins[i]-lastMax);
            lastMax = maxs[i];
        }
        i++;
    }
    return res;
}

int main(){
    cout<<maxGap({9,3,1,10})<<endl;
    cout<<maxGap({5,5,5,5})<<endl;


    return 0;
}