//
// Created by 钟奇龙 on 2019-05-20.
//

#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int> arr,int target){
    if(arr.size() == 0) return false;
    int left = 0;
    int right = arr.size()-1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(target == arr[mid]) return true;
        if(arr[mid] > arr[left]){
            if(target >= arr[left] && target < arr[mid]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }else if(arr[mid] == arr[left]){
            left++;
        }else{
            if(target > arr[mid] && target <= arr[right]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
    }
    return false;
}

