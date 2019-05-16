//
// Created by 钟奇龙 on 2019-05-16.
//
#include <iostream>
#include <vector>
using namespace std;
void modify(vector<int> &arr){
    if(arr.size() < 2) return;
    int even = 0;
    int odd = 1;
    while(even < arr.size() && odd < arr.size()){
        if(arr[arr.size()-1] & 1 != 0){
            swap(arr[odd],arr[arr.size()-1]);
            odd+=2;
        }else{
            swap(arr[even],arr[arr.size()-1]);
            even+=2;
        }
    }
}

int main(){
    vector<int> arr = {1,8,3,2,4,6};
    modify(arr);

    return 0;
}