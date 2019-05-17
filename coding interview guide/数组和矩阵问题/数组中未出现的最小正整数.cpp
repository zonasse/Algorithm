//
// Created by 钟奇龙 on 2019-05-17.
//

#include <iostream>
#include <vector>
using namespace std;

int missingNum(vector<int> arr){
    int i=0;
    while(i < arr.size()){
        if(arr[i] != i+1 && arr[i] >= 1 && arr[i] <= arr.size() && arr[i] != arr[arr[i]-1]){
            swap(arr[i],arr[arr[i]-1]);
        }else{
            i++;
        }
    }
    for(int i=0; i<arr.size(); ++i){
        if(arr[i] != i+1){
            return i+1;
        }
    }
    return arr.size()+1;
}

int main(){
    cout<<missingNum({-1,2,3,4})<<endl;
    cout<<missingNum({1,2,3,4})<<endl;

    return 0;
}