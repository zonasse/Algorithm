//
// Created by 钟奇龙 on 2019-05-20.
//
#include <vector>
#include <iostream>
using namespace std;

int getUpMedian(vector<int> arr1,vector<int> arr2){
    if(arr1.size() != arr2.size()) return INT_MIN;
    int start1 = 0;
    int end1 = arr1.size()-1;
    int start2 = 0;
    int end2 = arr2.size()-1;
    while(start1 < end1){
        int mid1 = start1 + (end1-start1)/2;
        int mid2 = start2 + (end2-start2)/2;
        if(arr1[mid1] == arr2[mid2]){
            return arr1[mid1];
        }
        int offset = (end1-start1+1) % 2 == 1 ? 0:1;
        if(arr1[mid1] > arr2[mid1]){
            end1 = mid1;
            start2 = mid2 + offset;
        }else{
            end2 = mid2;
            start1 = mid1 + offset;
        }
    }
    return min(arr1[start1],arr2[start2]);
}

int main(){
    cout<<getUpMedian({1,2,3,4,5},{1,2,3,4,5})<<endl;
    cout<<getUpMedian({1,2,3,4},{1,2,3,4})<<endl;

    return 0;
}