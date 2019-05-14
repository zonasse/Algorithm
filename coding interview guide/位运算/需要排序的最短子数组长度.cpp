//
// Created by 钟奇龙 on 2019-05-14.
//
#include <iostream>
#include <vector>
using namespace std;

int minSortLenght(vector<int> arr){
    if(arr.size() < 2) return 0;
    int noMinIndex = -1;
    int minValue = arr[arr.size()-1];
    for(int i=arr.size()-2; i>=0; --i){
        if(arr[i] < minValue){
            minValue = arr[i];
        }else{
            noMinIndex = i;
        }
    }
    if(noMinIndex == -1) return 0;
    int noMaxIndex = -1;
    int maxValue = arr[0];
    for(int i=1; i<arr.size(); ++i){
        if(arr[i] > maxValue){
            maxValue = arr[i];
        }else{
            noMaxIndex = i;
        }
    }
    return noMaxIndex - noMinIndex + 1;
}

int main(){
    vector<int> arr = {1,5,4,3,2,6,7};
    cout<<minSortLenght(arr)<<endl;
    return 0;
}