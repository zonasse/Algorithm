//
// Created by 钟奇龙 on 2019-05-16.
//
#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &arr){
    for(int i=0; i<arr.size(); ++i){
        while(arr[i] != i+1){
            swap(arr[arr[i]-1],arr[i]);
        }
    }
}

int main(){
    vector<int> arr = {3,1,2,5,4};
    sort(arr);

    return 0;
}