//
// Created by 钟奇龙 on 2019-05-16.
//

#include <iostream>
#include <vector>
using namespace std;

int getLessIndex(vector<int> arr){
    if(arr.size() == 0) return -1;
    if(arr.size() == 1 || arr[0] < arr[1]) return 0;
    if(arr[arr.size()-1] < arr[arr.size()-2]) return arr.size()-1;
    int left = 1;
    int right = arr.size()-2;
    while(left < right){
        int mid = left + (right-left)/2;
        if(arr[mid] > arr[mid-1]){
            right = mid-1;
        }else if(arr[mid] > arr[mid+1]){
            left = mid+1;
        }else{
            return mid;
        }
    }
    return left;
}

int main(){
    cout<<getLessIndex({2,1,5,3,4})<<endl;

    return 0;
}