//
// Created by 钟奇龙 on 2019-05-16.
//
#include <vector>
#include <iostream>
using namespace std;

int getMaxLength(vector<int> arr,int target){
    if(arr.size() == 0 || target <= 0) return 0;
    int maxLength = 0;
    int left = 0;
    int right = 0;
    int sum = arr[0];
    while(right < arr.size()){
        if(sum == target){
            maxLength = max(maxLength,right-left+1);
            sum -= arr[left];
            left++;
        }else if(sum > target){
            sum -= arr[left];
            left++;
        }else{
            right++;
            if(right == arr.size()) break;
            sum += arr[right];
        }
    }
    return maxLength;
}

int main(){
    cout<<getMaxLength({1,2,1,1,1},3)<<endl;

    return 0;
}
